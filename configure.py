"""
Configures the project for building. Invokes splat to split the binary and
creates build files for ninja.
"""
#! /usr/bin/env python3
import argparse
import os
import shutil
import sys
import json
import re
from pathlib import Path
from typing import Dict, List, Set, Union

import ninja_syntax
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

#MARK: Constants
ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"
OUTDIR = "out"

YAML_FILE = Path("config/sonic.yaml")
BASENAME = "SLUS_216.42"
LD_PATH = f"{BASENAME}.splat.ld"
ELF_PATH = f"{OUTDIR}/{BASENAME}"
MAP_PATH = f"{OUTDIR}/{BASENAME}.map"
PRE_ELF_PATH = f"{OUTDIR}/{BASENAME}.elf"

COMMON_INCLUDES = "-i include -i include/sdk/ee -i include/gcc"

CC_DIR = f"{TOOLS_DIR}/compilers/PS2/mwcps2-3.0.1b145-050209"
COMMON_COMPILE_FLAGS = f"-lang=c++ -O3"

WINE = "wine"

GAME_MWCC_CMD = f"{CC_DIR}/mwccps2 -c {COMMON_INCLUDES} {COMMON_COMPILE_FLAGS} $in"
COMPILE_CMD = f"{GAME_MWCC_CMD}"
if sys.platform == "linux" or sys.platform == "linux2":
    COMPILE_CMD = f"{WINE} {GAME_MWCC_CMD}"

CATEGORY_MAP = {
    "P2": "Engine",
    "splice": "Splice",
    "ps2t": "Tooling",
    "sce": "Libs",
    "data": "Data",
}

def clean():
    """
    Clean all products of the build process.
    """
    files_to_clean = [
        ".splache",
        ".ninja_log",
        "build.ninja",
        "permuter_settings.toml",
        "objdiff.json",
        LD_PATH
    ]
    for filename in files_to_clean:
        if os.path.exists(filename):
            os.remove(filename)

    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("obj", ignore_errors=True)
    shutil.rmtree("out", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)


def write_permuter_settings():
    """
    Write the permuter settings file, comprising the compiler and assembler commands.
    """
    with open("permuter_settings.toml", "w", encoding="utf-8") as f:
        f.write(f"""compiler_command = "{COMPILE_CMD} -D__GNUC__"
assembler_command = "mips-linux-gnu-as -march=r5900 -mabi=eabi -Iinclude"
compiler_type = "mwcc"

[preserve_macros]

[decompme.compilers]
"tools/build/cc/mwcc/mwccps2" = "mwcps2-3.0.1b145"
""")

#MARK: Build
def build_stuff(linker_entries: List[LinkerEntry], skip_checksum=False, objects_only=False, dual_objects=False):
    """
    Build the objects and the final ELF file.
    If objects_only is True, only build objects and skip linking/checksum.
    If dual_objects is True, build objects twice: once normally, once with -DSKIP_ASM.
    """
    built_objects: Set[Path] = set()
    objdiff_units = []  # For objdiff.json

    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        variables: Dict[str, str] = None,
        implicit_outputs: List[str] = None,
        out_dir: str = None,
        extra_flags: str = "",
        collect_objdiff: bool = False,
        orig_entry=None,
    ):
        """
        Helper function to build objects.
        """
        # Handle none parameters
        if variables is None:
            variables = {}

        if implicit_outputs is None:
            implicit_outputs = []

        # Convert object_paths to list if it is not already
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        # Determine output paths based on mode
        if out_dir:
            # --objects mode: use obj/target/ or obj/current/
            new_object_paths = []
            for obj in object_paths:
                obj = Path(obj)
                stem = obj.stem
                if obj.suffix in [".s", ".c", ".cpp"]:
                    stem = obj.stem
                else:
                    if obj.suffix == ".o" and obj.with_suffix("").suffix in [".s", ".c", ".cpp"]:
                        stem = obj.with_suffix("").stem
                target_dir = out_dir if out_dir else obj.parent
                new_obj = Path(target_dir) / (stem + ".o")
                new_object_paths.append(new_obj)
            object_paths = new_object_paths
        else:
            # Regular build mode: determine path based on source location
            new_object_paths = []
            for idx, obj in enumerate(object_paths):
                obj = Path(obj)
                src = Path(src_paths[idx]) if idx < len(src_paths) else None
                
                if src:
                    src_parts = src.parts
                    # Check if source is from asm/ or src/
                    if src_parts[0] == "asm":
                        # Assembly file: build/obj/ + rest of path
                        relative_path = Path(*src_parts[1:])
                        new_obj = Path("build") / "obj" / relative_path.with_suffix(".o")
                    elif src_parts[0] == "src":
                        # C/C++ file: build/src/ + rest of path
                        relative_path = Path(*src_parts[1:])
                        new_obj = Path("build") / "src" / relative_path.with_suffix(".o")
                    else:
                        # Fallback: use original path structure
                        new_obj = Path("build") / obj.with_suffix(".o")
                else:
                    # No source path, use original
                    new_obj = Path("build") / obj.with_suffix(".o")
                
                new_object_paths.append(new_obj)
            object_paths = new_object_paths

        # Add object paths to built_objects
        for idx, object_path in enumerate(object_paths):
            if object_path.suffix == ".o":
                built_objects.add(object_path)

            # Add extra_flags to variables if present
            build_vars = variables.copy()
            if extra_flags:
                build_vars["cflags"] = extra_flags
            ninja.build(
                outputs=[str(object_path)],
                rule=task,
                inputs=[str(s) for s in src_paths],
                variables=build_vars,
                implicit_outputs=implicit_outputs,
            )

            # Collect for objdiff.json if requested
            if collect_objdiff and orig_entry is not None:
                src = src_paths[0] if src_paths else None
                if src:
                    src = Path(src)
                    # Always use the final "matched" name, i.e. as if it will be in src/ with no asm/ prefix
                    try:
                        # If the file is in asm/, replace asm/ with nothing (just drop asm/)
                        if src.parts[0] == "asm":
                            rel = Path(*src.parts[1:])
                        elif src.parts[0] == "src":
                            rel = Path(*src.parts[1:])
                        else:
                            rel = src
                        # Remove extension for the name
                        name = str(rel.with_suffix(""))
                    except Exception:
                        name = str(src.with_suffix(""))
                else:
                    name = object_path.stem
                    # Ensure `rel` is defined so later code can compute src-based paths
                    try:
                        rel = Path(object_path)
                    except Exception:
                        rel = Path(str(object_path))

                # Determine the target_path based on the mode
                if out_dir and "target" in out_dir:
                    # --objects mode: use obj/target/ path
                    target_path = str(object_path)
                else:
                    # Regular mode: target is in build/obj/
                    target_path = str(Path("build") / "obj" / rel.with_suffix(".o"))

                # Determine if a .c or .cpp file exists in src/ for this unit (recursively)
                src_base = rel.with_suffix("")
                src_c_files = list(Path("src").rglob(src_base.name + ".c"))
                src_cpp_files = list(Path("src").rglob(src_base.name + ".cpp"))
                has_src = bool(src_c_files or src_cpp_files)

                # Determine the category based on the name
                categories = [name.split("/")[0]]
                if "P2/splice/" in name:
                    categories.append("splice")
                elif "P2/ps2t" in name:
                    categories.append("ps2t")

                unit = {
                    "name": name,
                    "target_path": target_path,
                    "metadata": {
                        "progress_categories": categories,
                    }
                }

                if has_src:
                    if out_dir and "target" in out_dir:
                        # --objects mode: replace 'target' with 'current'
                        op = Path(object_path)
                        parts = list(op.parts)
                        for idx, part in enumerate(parts):
                            if part == "target":
                                parts[idx] = "current"
                                break
                        base_path = str(Path(*parts))
                    else:
                        # Regular mode: base is in build/src/
                        base_path = str(Path("build") / "src" / rel.with_suffix(".o"))
                    unit["base_path"] = base_path
                objdiff_units.append(unit)

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w", encoding="utf-8"), width=9999)

    #MARK: Rules
    cross = "mips-linux-gnu-"
    binutils_prefix = TOOLS_DIR / "binutils"
    
    # Use custom binutils if available, otherwise use system binutils
    if (binutils_prefix / f"{cross}as").exists() or (binutils_prefix / f"{cross}as.exe").exists():
        cross_path = f"{binutils_prefix}/{cross}"
    else:
        cross_path = cross

    ld_args = "-EL -T config/undefined_syms_auto.txt -T config/undefined_funcs_auto.txt -Map $mapfile -T $in -o $out"

    ninja.rule(
        "as",
        description="as $in",
        command=f"{cross_path}as -no-pad-sections -EL -march=5900 -mabi=eabi -Iinclude -o $out $in",
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{COMPILE_CMD} $cflags -o $out",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{cross_path}ld {ld_args}",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    ninja.rule(
        "elf",
        description="elf $out",
        command=f"{cross_path}objcopy $in $out -O binary",
    )

    #MARK: Build
    # Build all the objects
    for entry in linker_entries:
        seg = entry.segment

        if seg.type[0] == ".":
            continue

        if entry.object_path is None:
            continue

        if isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as", collect_objdiff=True, orig_entry=entry)
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "cc", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "cc", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "cc", collect_objdiff=True, orig_entry=entry)
        elif isinstance(seg, splat.segtypes.common.databin.CommonSegDatabin):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as", collect_objdiff=True, orig_entry=entry)
        elif isinstance(seg, splat.segtypes.common.rodatabin.CommonSegRodatabin):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as", collect_objdiff=True, orig_entry=entry)
        elif isinstance(seg, splat.segtypes.common.textbin.CommonSegTextbin):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as", collect_objdiff=True, orig_entry=entry)
        elif isinstance(seg, splat.segtypes.common.bin.CommonSegBin):
            if dual_objects:
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/target", collect_objdiff=True, orig_entry=entry)
                build(entry.object_path, entry.src_paths, "as", out_dir="obj/current", extra_flags="-DSKIP_ASM")
            else:
                build(entry.object_path, entry.src_paths, "as", collect_objdiff=True, orig_entry=entry)
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    # Scan src/ folder for manually created C/C++ files that splat doesn't know about
    if Path("src").exists():
        for src_file in Path("src").rglob("*.cpp"):
            # Build this C++ file
            build([src_file], [src_file], "cc", collect_objdiff=True, orig_entry=None)
        
        for src_file in Path("src").rglob("*.c"):
            # Build this C file
            build([src_file], [src_file], "cc", collect_objdiff=True, orig_entry=None)

    if objects_only:
        # Write objdiff.json if dual_objects (i.e. --objects)
        if dual_objects:
            objdiff = {
                "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
                "custom_make": "ninja",
                "custom_args": [],
                "build_target": False,
                "build_base": True,
                "watch_patterns": [
                    "src/**/*.c",
                    "src/**/*.cp",
                    "src/**/*.cpp",
                    "src/**/*.cxx",
                    "src/**/*.h",
                    "src/**/*.hp",
                    "src/**/*.hpp",
                    "src/**/*.hxx",
                    "src/**/*.s",
                    "src/**/*.S",
                    "src/**/*.asm",
                    "src/**/*.inc",
                    "src/**/*.py",
                    "src/**/*.yml",
                    "src/**/*.txt",
                    "src/**/*.json"
                ],
                "units": objdiff_units,
                "progress_categories": [ {"id": id, "name": name} for id, name in CATEGORY_MAP.items() ],
            }
            with open("objdiff.json", "w", encoding="utf-8") as f:
                json.dump(objdiff, f, indent=2)
        return

    # Write objdiff.json for regular build mode
    if objdiff_units:
        objdiff = {
            "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
            "custom_make": "ninja",
            "custom_args": [],
            "build_target": False,
            "build_base": True,
            "watch_patterns": [
                "src/**/*.c",
                "src/**/*.cp",
                "src/**/*.cpp",
                "src/**/*.cxx",
                "src/**/*.h",
                "src/**/*.hp",
                "src/**/*.hpp",
                "src/**/*.hxx",
                "src/**/*.s",
                "src/**/*.S",
                "src/**/*.asm",
                "src/**/*.inc",
                "src/**/*.py",
                "src/**/*.yml",
                "src/**/*.txt",
                "src/**/*.json"
            ],
            "units": objdiff_units,
            "progress_categories": [ {"id": id, "name": name} for id, name in CATEGORY_MAP.items() ],
        }
        with open("objdiff.json", "w", encoding="utf-8") as f:
            json.dump(objdiff, f, indent=2)

    ninja.build(
        PRE_ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": MAP_PATH},
    )

    ninja.build(
        ELF_PATH,
        "elf",
        PRE_ELF_PATH,
    )

    if not skip_checksum:
        ninja.build(
            ELF_PATH + ".ok",
            "sha1sum",
            "config/checksum.sha1",
            implicit=[ELF_PATH],
        )
    else:
        print("Skipping checksum step")

#MARK: Short loop fix
# Pattern to workaround unintended nops around loops
COMMENT_PART = r"\/\* (.+) ([0-9A-Z]{2})([0-9A-Z]{2})([0-9A-Z]{2})([0-9A-Z]{2}) \*\/"
INSTRUCTION_PART = r"(\b(bne|bnel|beq|beql|bnez|bnezl|beqzl|bgez|bgezl|bgtz|bgtzl|blez|blezl|bltz|bltzl|b)\b.*)"
OPCODE_PATTERN = re.compile(f"{COMMENT_PART}  {INSTRUCTION_PART}")

PROBLEMATIC_FUNCS = set(
    [
        "UpdateJtActive__FP2JTP3JOYf", # P2/jt
        "AddMatrix4Matrix4__FP7MATRIX4N20", # P2/mat
        "FInvertMatrix__FiPfT1", # P2/mat
        "PwarpFromOid__F3OIDT0", # P2/xform
        "RenderMsGlobset__FP2MSP2CMP2RO", # P2/ms
        "ProjectBlipgTransform__FP5BLIPGfi", # P2/blip
        "DrawTvBands__FP2TVR4GIFS", # P2/tv
        "LoadShadersFromBrx__FP18CBinaryInputStream", # P2/shd
        "FillShaders__Fi", # P2/shd
        "FUN_001aea70", # P2/screen
        "ApplyDzg__FP3DZGiPiPPP2SOff", # P2/dzg
        "BounceRipgRips__FP4RIPG", # P2/rip
        "UpdateStepPhys__FP4STEP", # P2/step
        "PredictAsegEffect__FP4ASEGffP3ALOT3iP6VECTORP7MATRIX3T6T6", # P2/aseg
        "ExplodeExplsExplso__FP5EXPLSP6EXPLSO", # P2/emitter
        "UpdateShadow__FP6SHADOWf" # P2/shadow
    ]
)

def replace_instructions_with_opcodes(asm_folder: Path) -> None:
    """
    Replace branch instructions with raw opcodes for functions that trigger the short loop bug.
    """
    nm_folder = ROOT / asm_folder / "nonmatchings"

    for p in nm_folder.rglob("*.s"):
        if p.stem not in PROBLEMATIC_FUNCS:
            continue

        with p.open("r") as file:
            content = file.read()

        if re.search(OPCODE_PATTERN, content):
            # Reference found
            # Embed the opcode, we have to swap byte order for correct endianness
            content = re.sub(
                OPCODE_PATTERN,
                r"/* \1 \2\3\4\5 */  .word      0x\5\4\3\2 /* \6 */",
                content,
            )

            # Write the updated content back to the file
            with p.open("w") as file:
                file.write(content)

#MARK: Main
def main():
    """
    Main function, parses arguments and runs the configuration.
    """
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean artifacts and build",
        action="store_true",
    )
    parser.add_argument(
        "-C",
        "--clean-only",
        help="Only clean artifacts",
        action="store_true",
    )
    parser.add_argument(
        "-s",
        "--skip-checksum",
        help="Skip the checksum step",
        action="store_true",
    )
    parser.add_argument(
        "--objects",
        help="Build objects to obj/target and obj/current (with -DSKIP_ASM), skip linking and checksum",
        action="store_true",
    )
    parser.add_argument(
        "-noloop",
        "--no-short-loop-workaround",
        help="Do not replace branch instructions with raw opcodes for functions that trigger the short loop bug",
        action="store_true",
    )
    args = parser.parse_args()

    do_clean = (args.clean or args.clean_only) or False
    do_skip_checksum = args.skip_checksum or False
    do_objects = args.objects or False

    if do_clean:
        clean()
        if args.clean_only:
            return

    split.main([YAML_FILE], modes="all", verbose=False)

    linker_entries = split.linker_writer.entries

    if do_objects:
        build_stuff(linker_entries, skip_checksum=True, objects_only=True, dual_objects=True)
    else:
        build_stuff(linker_entries, do_skip_checksum)

    write_permuter_settings()

    if not args.no_short_loop_workaround:
        replace_instructions_with_opcodes(split.config["options"]["asm_path"])

if __name__ == "__main__":
    main()
