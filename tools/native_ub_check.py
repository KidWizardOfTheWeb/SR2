#!/usr/bin/env python3
"""Check configure.py's native_mwcc_exclude with tools/ub_probe.py.

    python3 tools/native_ub_check.py [--native PATH] [-j N] [--no-cache]

Exits 1 with the entries to add or remove (cache: build/ub_probe_cache.json).
"""

import argparse
import os
import re
import shlex
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ub_probe  # noqa: E402


def excluded():
    """configure.py's native_mwcc_exclude entries."""
    text = open(os.path.join(ROOT, "configure.py")).read()
    m = re.search(r"native_mwcc_exclude = \[(.*?)\n\]", text, re.S)
    return re.findall(r'^\s*"([^"]+)"', m.group(1), re.M) if m else []


def commands(native):
    """(source, native compile command) for every MWCC unit in build.ninja."""
    ninja = os.path.join(ROOT, ".venv", "bin", "ninja")
    if not os.path.exists(ninja):
        ninja = "ninja"
    out = subprocess.run([ninja, "-t", "commands"], cwd=ROOT, capture_output=True, text=True, check=True)
    cmds = []
    for line in out.stdout.splitlines():
        if "-precompile" in line:
            continue
        argv = shlex.split(line.split(" && ")[0])
        cc = next((i for i, x in enumerate(argv) if x.endswith("mwccps2.exe") or x.endswith("/mwccps2")), None)
        if cc is None:
            continue
        rest = argv[cc + 1 :]
        if "-o" not in rest or "-c" not in rest:
            continue
        # the native reads its own precompiled header
        rest = [x.replace("/include-orig/", "/include/") for x in rest]
        o = rest.index("-o")
        src = rest[rest.index("-c") + 1]
        rest[o + 1] = os.path.join("build", "ub_probe", rest[o + 1])
        cmds.append((src, [native] + rest))
    return cmds


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--native", default=os.path.join(ROOT, "tools", "mwccps2-native", "mwccps2"))
    p.add_argument("-j", type=int, default=os.cpu_count() or 4)
    p.add_argument("--no-cache", action="store_true")
    a = p.parse_args()
    if not os.path.isfile(a.native):
        sys.exit(f"{a.native}: not found (python3 tools/get_native_mwcc.py)")
    native = os.path.abspath(a.native)

    os.chdir(ROOT)
    cmds = commands(native)
    listfile = os.path.join("build", "ub_probe", "commands.txt")
    os.makedirs(os.path.dirname(listfile), exist_ok=True)
    with open(listfile, "w") as f:
        f.write("".join(shlex.join(c) + "\n" for _, c in cmds))
    out_to_src = {c[c.index("-o") + 1]: s for s, c in cmds}

    env = dict(os.environ, MWCC_DRIVE="Z", MWCC_SJIS="1")
    probe = [sys.executable, os.path.join("tools", "ub_probe.py"), "-j", str(a.j), "--cmds", listfile]
    if not a.no_cache:
        probe += ["--cache", os.path.join("build", "ub_probe_cache.json")]
    r = subprocess.run(probe, env=env, capture_output=True, text=True)
    sys.stderr.write(r.stderr)

    found = {}
    for line in r.stdout.splitlines():
        out, kind, *fns = line.split("\t")
        if kind == "(compile failed)":
            print(f"{out_to_src.get(out, out)}: native compile failed", file=sys.stderr)
            continue
        found.setdefault(out_to_src.get(out, out), []).append((kind, fns[0] if fns else ""))

    listed = excluded()
    covered = lambda src: any(src.endswith(x) for x in listed)
    missing = sorted(s for s in found if not covered(s))
    stale = sorted(x for x in listed if not any(s.endswith(x) for s in found))
    for src, kinds in sorted(found.items()):
        print(f"{'  listed' if covered(src) else 'MISSING '} {src}: " + "; ".join(f"{k} {f}" for k, f in kinds))
    for x in stale:
        print(f"STALE    {x}: no longer depends on the original's uninitialised memory")
    if missing or stale:
        print("\nconfigure.py native_mwcc_exclude needs updating:", file=sys.stderr)
        for s in missing:
            print(f'    "{s}",  # add', file=sys.stderr)
        for x in stale:
            print(f'    "{x}",  # remove', file=sys.stderr)
        sys.exit(1)
    print(f"native_mwcc_exclude is up to date ({len(listed)} units)")


if __name__ == "__main__":
    main()
