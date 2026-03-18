#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "SLUS-21642-PROTO-070901",  # 0 - Sep 1, 2007 prototype
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--ninja",
    metavar="BINARY",
    type=Path,
    help="path to ninja binary (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
parser.add_argument(
    "--no-short-loop-workaround",
    dest="short_loop_workaround",
    action="store_false",
    help="disable short loop workaround for MWCCPS2",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.ninja_path = args.ninja
config.progress = args.progress
config.short_loop_workaround = args.short_loop_workaround
if not is_windows():
    config.wrapper = args.wrapper

# # Don't build asm unless we're --non-matching
# if not config.non_matching:
#     config.asm_dir = None
# else:
#     # Set asm_dir to version-specific path
#     config.asm_dir = config.out_path() / "asm"

# Set asm_dir to version-specific path
config.asm_dir = config.out_path() / "asm"

# Tool versions
config.binutils_tag = "2.45"
config.compilers_tag = "20250812"
config.mwccps2_tag = "3.0.1b145-050209"
config.objdiff_tag = "v3.5.1"
config.wibo_tag = "1.0.0-beta.5"

# Project
config.config_path = Path("config") / config.version / "sonic.yaml"
config.check_sha_path = Path("config") / config.version / "checksum.sha1"
config.symbol_addrs_path = Path("config") / config.version / "symbol_addrs.txt"
config.ldflags = [
    "-map",  # Generate map file
]
if args.map:
    pass  # -map is already in ldflags

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Base flags for MWCCPS2
cflags_base = [
    "-lang=c++",
    "-O3",
    "-i include",
    f"-DBUILD_VERSION={version_num}",
]

# Debug flags
if args.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

config.asflags = [
    "-no-pad-sections",
    "-EL",
    "-march=5900",
    "-mabi=eabi",
    "-Iinclude",
]

# Compiler version for MWCCPS2
config.linker_version = f"PS2/mwcps2-{config.mwccps2_tag}"

Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching

config.warn_missing_config = True
config.warn_missing_source = False
config.scratch_preset_id = 213

# Library configuration
config.libs = [
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_base,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "usr/local/sce/ee/lib/crt0.s"),
            Object(NonMatching, "Develop/Projects/SR2/pgm/src/System/NewDelete.c"),
            Object(NonMatching, "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2Heap.c"),
            Object(NonMatching, "usr/local/metrowerks/PS2_Support/gcc_wrapper.c"),
            Object(NonMatching, "usr/local/metrowerks/PS2_Support/runtime/asmtu_Support/mwUtils_PS2.s"),
            Object(NonMatching, "usr/local/metrowerks/PS2_Support/asmtu_Support/arraycondes.s"),
            Object(NonMatching, "usr/local/metrowerks/PS2_Support/asmtu_Support/StaticInitializers.s"),
            Object(NonMatching, "usr/local/metrowerks/PS2_Support/asmtu_Support/__ptmf.s"),
            # Add more objects here following your sonic.yaml structure
            Object(Matching, "Develop/Projects/SR2/pgm/src/Object/Player/Performance.cpp"),
        ],
    },
]

# Optional extra categories for progress tracking
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
