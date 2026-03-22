Sonic Riders: Zero Gravity  
[![Build Status]][actions] [![Code Progress]][progress] [![Data Progress]][progress] [![Discord Badge]][discord]
=============
[Build Status]: https://github.com/KidWizardOfTheWeb/SR2/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/KidWizardOfTheWeb/SR2/actions/workflows/build.yml
[Code Progress]: https://decomp.dev/KidWizardOfTheWeb/SR2.svg?mode=shield&measure=code&label=Code
[Data Progress]: https://decomp.dev/KidWizardOfTheWeb/SR2.svg?mode=shield&measure=data&label=Data
[progress]: https://decomp.dev/KidWizardOfTheWeb/SR2
[Discord Badge]: https://img.shields.io/discord/1454591380499337218?color=%237289DA&logo=discord&logoColor=%23FFFFFF
[discord]: https://discord.gg/ntaraNahDa

A work-in-progress decompilation of [*Sonic Riders: Zero Gravity*](https://en.wikipedia.org/wiki/Sonic_Riders:_Zero_Gravity) for the PlayStation 2.

This repository does **not** contain any game assets or assembly whatsoever. An existing copy of the game is required.

Supported versions:

- `SLUS_216.42`: Prototype (USA, 2007-09-01)

## Dependencies

### Windows

On Windows, it's **highly recommended** to use native tooling. WSL or msys2 are **not** required.  
When running under WSL, [objdiff](#diffing) is unable to get filesystem notifications for automatic rebuilds.

- Install [Python](https://www.python.org/downloads/) and add it to `%PATH%`.
  - Also available from the [Windows Store](https://apps.microsoft.com/store/detail/python-311/9NRWMJP3717K).
- Download [ninja](https://github.com/ninja-build/ninja/releases) and add it to `%PATH%`.
  - Quick install via pip: `pip install ninja`

### macOS

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages):

  ```sh
  brew install ninja
  ```

[wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

### Linux

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages).

[wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

## Building

- Clone the repository:

  ```sh
  git clone https://github.com/KidWizardOfTheWeb/SR2.git
  ```

- Copy your game's `SLUS_216.42` ELF file to `orig/SLUS-21642-PROTO-070901/`.

- Install Python dependencies:

  ```sh
  pip install -r requirements.txt
  ```

- Configure:

  ```sh
  python configure.py
  ```

- Build:

  ```sh
  ninja
  ```

> **Windows note:** If you get a charmap error, run `python -X utf8 configure.py` or set your Python environment to use UTF-8 by default.

## Diffing

Once the initial build succeeds, an `objdiff.json` should exist in the project root.

Download the latest release from [encounter/objdiff](https://github.com/encounter/objdiff). Under project settings, set `Project directory`. The configuration should be loaded automatically.

Select an object from the left sidebar to begin diffing. Changes to the project will rebuild automatically: changes to source files, headers, or `configure.py`.

![](assets/objdiff.png)
