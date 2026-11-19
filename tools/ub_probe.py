#!/usr/bin/env python3
"""Find the functions whose output depends on the original compiler's undefined behaviour.

(A copy of mweppc's tools/mwccpsp/ub_probe.py; tools/native_ub_check.py runs it on this project.)

The native compilers give each place where the original reads memory it never wrote a
fixed value (include/compiler/ub_probe.h); MWCC_UB_FILL overrides it per kind. This
compiles a unit with the default and with other fills and reports the functions whose
code or relocations change: those are the ones where the original's own output depends
on leftover bytes, so the native (or the original under another host) can differ there.

    ub_probe.py [--kinds operand,hascall] [--values 0xffff,0x8] -- NATIVE ARGS... -o OUT.o
    ub_probe.py [--kinds ...] [--values ...] [-j N] [--cache FILE] --cmds FILE

FILE has one compile command per line (a shell command line with -o OUT); the report
has one line per affected unit: OUT  kind  function[,function...].

Kinds (see docs/mwccps2-ub): operand = a memory/immediate operand's flags (UB 2: b119,
b198), hascall = a constant node's hascall byte (UB 1: b69). A kind a build doesn't have
changes nothing.

--cache FILE keeps each unit's result with the compiler's hash, its command and the
hashes of the files it read (from the -MMD dependency file of the default build); a
unit is compiled again only when one of those changed.
"""

import argparse
import hashlib
import json
import os
import re
import shlex
import struct
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

DEFAULT_VALUES = {"operand": ["0x8", "0xffff"], "hascall": ["0xff"]}


def functions(path):
    """{function: (code bytes, relocations)} of an ELF32 object."""
    d = open(path, "rb").read()
    if d[:4] != b"\x7fELF":
        raise ValueError(f"{path}: not ELF")
    e = "<" if d[5] == 1 else ">"
    (shoff,) = struct.unpack_from(e + "I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(e + "HHH", d, 0x2E)
    secs = [struct.unpack_from(e + "IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]

    def data(i):
        s = secs[i]
        return b"" if s[1] == 8 else d[s[4] : s[4] + s[5]]

    rels = {}
    symtab = None
    for i, s in enumerate(secs):
        if s[1] in (9, 4):  # SHT_REL, SHT_RELA
            rels.setdefault(s[7], []).append(data(i))
        elif s[1] == 2:
            symtab = i
    out = {}
    if symtab is None:
        return out
    strtab = data(secs[symtab][6])
    syms = data(symtab)
    for k in range(0, len(syms), 16):
        name, value, size, info, _, shndx = struct.unpack_from(e + "IIIBBH", syms, k)
        if info & 0xF != 2 or not 0 < shndx < len(secs):
            continue
        nm = strtab[name : strtab.index(b"\0", name)].decode("latin-1")
        code = data(shndx)[value : value + size]
        out[nm] = (code, b"".join(rels.get(shndx, [])))
    return out


def sha(path):
    try:
        return hashlib.sha256(open(path, "rb").read()).hexdigest()
    except OSError:
        return None


def read_deps(dfile):
    """The files a -MMD dependency file lists (MWCC_DRIVE's drive letter removed)."""
    try:
        text = open(dfile, encoding="latin-1").read()
    except OSError:
        return None
    text = text.replace("\\\n", " ")
    _, _, rest = text.partition(": ")
    return [re.sub(r"^[A-Za-z]:(?=/)", "", t) for t in rest.split()]


def compile_once(argv, out, fill):
    env = dict(os.environ)
    env.pop("MWCC_UB_FILL", None)
    if fill:
        env["MWCC_UB_FILL"] = fill
    if os.path.exists(out):
        os.remove(out)
    subprocess.run(argv, capture_output=True, env=env)
    return functions(out) if os.path.exists(out) else None


def probe(argv, kinds, values):
    """([(kind, [functions])], {dependency: sha256}) for one compile command."""
    o = argv.index("-o")
    real = argv[o + 1]
    with tempfile.TemporaryDirectory() as tmp:

        def run(tag, fill, extra=()):
            a = list(argv) + list(extra)
            a[o + 1] = os.path.join(tmp, tag + os.path.splitext(real)[1])
            return compile_once(a, a[o + 1], fill)

        base = run("base", None, () if "-MMD" in argv else ("-gccdep", "-MMD"))
        if base is None:
            return None, None
        deps = read_deps(os.path.join(tmp, "base.d"))
        deps = {d: sha(d) for d in deps} if deps else None
        found = []
        for kind in kinds:
            changed = set()
            for v in values.get(kind) or DEFAULT_VALUES.get(kind, ["0xff"]):
                other = run(f"{kind}_{v}", f"{kind}={v}")
                if other is None:
                    changed.add("(compile failed)")
                    continue
                for fn in set(base) | set(other):
                    if base.get(fn) != other.get(fn):
                        changed.add(fn)
            if changed:
                found.append((kind, sorted(changed)))
        return found, deps


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--kinds", default="operand,hascall")
    p.add_argument("--values", help="fill values for every kind (default: per kind)")
    p.add_argument("--cmds", help="file of compile commands, one per line")
    p.add_argument("-j", type=int, default=os.cpu_count() or 4)
    p.add_argument("--cwd", help="directory to run the commands in")
    p.add_argument("--cache", help="JSON file of earlier results, reused while nothing changed")
    p.add_argument("argv", nargs=argparse.REMAINDER)
    a = p.parse_args()
    kinds = [k for k in a.kinds.split(",") if k]
    values = {k: a.values.split(",") for k in kinds} if a.values else {}
    if a.cwd:
        os.chdir(a.cwd)

    if a.cmds:
        cmds = [shlex.split(l) for l in open(a.cmds) if l.strip()]
    else:
        argv = a.argv[1:] if a.argv[:1] == ["--"] else a.argv
        if "-o" not in argv:
            p.error("the compile command needs -o OUT")
        cmds = [argv]

    cache = {}
    if a.cache and os.path.exists(a.cache):
        cache = json.load(open(a.cache))
    ccs = {}

    def cc_hash(path):
        if path not in ccs:
            ccs[path] = sha(path)
        return ccs[path]

    def one(argv):
        out = argv[argv.index("-o") + 1]
        key = {"argv": argv, "cc": cc_hash(argv[0]), "kinds": kinds, "values": values}
        hit = cache.get(out)
        if hit and hit["key"] == key and hit["deps"] and all(sha(d) == h for d, h in hit["deps"].items()):
            return out, [tuple(x) for x in hit["result"]] if hit["result"] is not None else None, True
        found, deps = probe(argv, kinds, values)
        if found is not None and deps:
            cache[out] = {"key": key, "deps": deps, "result": found}
        return out, found, False

    affected = failed = cached = 0
    with ThreadPoolExecutor(a.j) as ex:
        for out, found, was_cached in ex.map(one, cmds):
            cached += was_cached
            if found is None:
                failed += 1
                print(f"{out}\t(compile failed)", flush=True)
            for kind, fns in found or []:
                affected += 1
                print(f"{out}\t{kind}\t{','.join(fns)}", flush=True)
    if a.cache:
        tmp = a.cache + ".tmp"
        json.dump(cache, open(tmp, "w"))
        os.replace(tmp, a.cache)
    print(
        f"# {len(cmds)} units ({cached} from the cache), {affected} affected (unit, kind) pairs, {failed} failed",
        file=sys.stderr,
    )


if __name__ == "__main__":
    main()
