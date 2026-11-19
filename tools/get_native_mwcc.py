#!/usr/bin/env python3
"""Install mweppc's native mwccps2 b198 release to tools/mwccps2-native/mwccps2.

    python3 tools/get_native_mwcc.py [--archive FILE | --binary FILE] [--force]

Enable it with SR2_MWCC_NATIVE=1 or configure.py --native-mwcc.
"""

from __future__ import annotations

import argparse
import hashlib
import io
import os
import platform
import shutil
import sys
import tarfile
import urllib.request
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
DEST = REPO / "tools" / "mwccps2-native" / "mwccps2"

RELEASE_URL = "https://github.com/sozud/mweppc/releases/download/mwccps2-b198-v1.0.0"
SHA256 = {
    "mwccps2-b198-native64-linux-amd64.tar.gz": "1629edb3a93f9244384bb63171c9a71242890b354e833f09f15b19d6d48da4bb",
    "mwccps2-b198-native64-darwin-arm64.tar.gz": "7bdee39d464a108159b1488329119ccd10349c12ec03f4eab1295116d1e58d98",
    "mwccps2-b198-native64-darwin-amd64.tar.gz": "5c23b1f1dfa211653245c3d13f5b7f66eaa9342bd76236f42036ec6e2882372f",
}


def asset_name() -> str:
    system = platform.system()
    machine = platform.machine().lower()
    arch = {"x86_64": "amd64", "amd64": "amd64", "arm64": "arm64", "aarch64": "arm64"}.get(machine)
    os_name = {"Linux": "linux", "Darwin": "darwin"}.get(system)
    name = f"mwccps2-b198-native64-{os_name}-{arch}.tar.gz"
    if name not in SHA256:
        sys.exit(
            f"get_native_mwcc: no native mwccps2 build for {system} {machine}; "
            "use the original compiler (SR2_MWCC_NATIVE=0)"
        )
    return name


def install(blob: bytes) -> None:
    DEST.parent.mkdir(parents=True, exist_ok=True)
    tmp = DEST.with_suffix(".tmp")
    tmp.write_bytes(blob)
    tmp.chmod(0o755)
    tmp.replace(DEST)
    print(f"installed {DEST.relative_to(REPO)}; enable it with SR2_MWCC_NATIVE=1")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--archive", type=Path, help="install this release tarball instead of downloading it")
    ap.add_argument("--binary", type=Path, help="install this native compiler binary")
    ap.add_argument("--force", action="store_true", help="replace an installed compiler")
    a = ap.parse_args()

    if DEST.is_file() and not a.force:
        print(f"{DEST.relative_to(REPO)} is already installed (--force to replace it)")
        return
    if a.binary:
        install(a.binary.read_bytes())
        return

    name = asset_name()
    if a.archive:
        data = a.archive.read_bytes()
    else:
        url = f"{os.environ.get('SR2_MWCC_NATIVE_URL', RELEASE_URL)}/{name}"
        print(f"downloading {url}")
        with urllib.request.urlopen(url, timeout=120) as r:
            data = r.read()
    digest = hashlib.sha256(data).hexdigest()
    if SHA256[name] is not None and digest != SHA256[name]:
        sys.exit(f"get_native_mwcc: {name} has SHA-256 {digest}, expected {SHA256[name]}")
    if SHA256[name] is None:
        print(f"warning: no SHA-256 pinned for {name} (got {digest})")

    stem = name[: -len(".tar.gz")]
    with tarfile.open(fileobj=io.BytesIO(data), mode="r:gz") as tar:
        member = next((m for m in tar.getmembers() if m.isfile() and Path(m.name).name == stem), None)
        if member is None:
            sys.exit(f"get_native_mwcc: {name} does not contain {stem}")
        blob = tar.extractfile(member).read()
    install(blob)


if __name__ == "__main__":
    main()
