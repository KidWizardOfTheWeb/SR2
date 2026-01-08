#!/bin/bash

set -e

echo "Starting Sonic Riders Zero Gravity decomp setup..."
echo

# Get script directory and move to project root
SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd "$SCRIPT_DIR/.."

# Install Python dependencies
echo "Installing Python dependencies..."
python3 -m pip install -r requirements.txt
echo

# Elevate privileges for system package installation
echo "This script requires sudo access to install system packages."
sudo -v

# Check if sudo is available
if [ "$EUID" -ne 0 ]; then
    echo "Installing dependencies requires sudo. Please enter your password."
fi

# Update apt packages
echo "Updating package lists..."
sudo apt-get update

# Setup wine
echo "Setting up Wine (32-bit support)..."
if ! dpkg -l | grep -q wine32; then
    sudo dpkg --add-architecture i386
    sudo apt-get update
    sudo apt-get install -y wine32
    echo "Wine installed successfully!"
else
    echo "Wine already installed."
fi
echo

# Install MIPS binutils
echo "Setting up MIPS binutils..."
if ! dpkg -l | grep -q binutils-mips-linux-gnu; then
    sudo apt-get install -y binutils-mips-linux-gnu
    echo "MIPS binutils installed successfully!"
else
    echo "MIPS binutils already installed."
fi
echo

# Download and setup base compilers
echo "Setting up base compilers..."
if [ ! -d "tools/compilers" ]; then
    echo "Downloading base compilers package..."
    wget -q --show-progress -O /tmp/compilers_latest.zip "https://files.decomp.dev/compilers_latest.zip"
    
    echo "Extracting base compilers..."
    unzip -q /tmp/compilers_latest.zip -d tools/compilers
    rm /tmp/compilers_latest.zip
    echo "Base compilers installed successfully!"
else
    echo "Base compilers already exist."
fi
echo

# Download and setup PS2 compiler
echo "Setting up MWCCPS2 compiler..."

PS2_ROOT="tools/compilers/PS2"
COMPILER_DIR="$PS2_ROOT/mwcps2-3.0.1b198-051011"

if [ ! -d "$COMPILER_DIR" ]; then
    echo "Downloading MWCCPS2 compiler..."
    
    mkdir -p "$PS2_ROOT"
    
    wget -q --show-progress -O /tmp/mwccps2.tar.gz "https://github.com/decompme/compilers/releases/download/compilers/mwcps2-3.0.1b198-051011.tar.gz"
    
    echo "Extracting MWCCPS2 compiler..."
    mkdir -p "$COMPILER_DIR"
    tar -xzf /tmp/mwccps2.tar.gz -C "$COMPILER_DIR"
    
    # Cleanup temporary files
    rm /tmp/mwccps2.tar.gz
    
    # Patch PS2 compiler
    echo "Patching PS2 compiler DLLs..."
    GC_DLL_PATH="tools/compilers/GC/3.0a5"
    
    if [ -f "$GC_DLL_PATH/lmgr8c.dll" ]; then
        cp "$GC_DLL_PATH/lmgr8c.dll" "$COMPILER_DIR/"
        cp "$GC_DLL_PATH/lmgr326b.dll" "$COMPILER_DIR/"
        echo "DLLs replaced successfully!"
    else
        echo "[!] Warning: GC DLLs not found at $GC_DLL_PATH. Replacement skipped."
    fi
    
    echo "MWCCPS2 compiler installed successfully!"
else
    echo "MWCCPS2 compiler already installed."
fi
echo

# Download and setup objdiff-cli
echo "Setting up objdiff-cli..."
OBJDIFF_DIR="tools/objdiff"
OBJDIFF_BIN="$OBJDIFF_DIR/objdiff-cli"

if [ ! -f "$OBJDIFF_BIN" ]; then
    echo "Downloading objdiff-cli for Linux x86_64..."
    
    mkdir -p "$OBJDIFF_DIR"
    
    wget -q --show-progress -O "$OBJDIFF_BIN" "https://github.com/encounter/objdiff/releases/download/v3.5.1/objdiff-cli-linux-x86_64"
    chmod +x "$OBJDIFF_BIN"
    
    echo "objdiff-cli installed successfully!"
else
    echo "objdiff-cli already installed."
fi
echo

# Check for game binary
echo "Setup complete!"
echo
if [ ! -f "disc/SLUS_216.42" ]; then
    echo "[!] Next step: Copy SLUS_216.42 from your copy of the game to the 'disc' directory."
    echo "    Then build the project by running: python3 configure.py"
else
    echo "Game binary found! You can now build the project by running: python3 configure.py"
fi
echo