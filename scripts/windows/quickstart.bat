@echo off
setlocal

echo Starting Sonic Riders Zero Gravity decomp setup...
echo.

REM Get script directory and move to project root
cd /d "%~dp0..\.."

REM Install Python dependencies
echo Installing Python dependencies...
python -m pip install -r requirements.txt
if errorlevel 1 (
    echo Error: Failed to install Python dependencies
    exit /b 1
)
echo.

REM Download and setup MIPS binutils
echo Setting up MIPS binutils...
if not exist "tools\binutils" (
    echo Downloading MIPS binutils for Windows...
    curl -L "https://github.com/dbalatoni13/mips-binutils/releases/download/2.45/windows-x86_64.zip" -o "%TEMP%\mips-binutils.zip"
    if errorlevel 1 (
        echo Error: Failed to download MIPS binutils
        exit /b 1
    )
    
    echo Extracting MIPS binutils...
    powershell -Command "Expand-Archive -Path '%TEMP%\mips-binutils.zip' -DestinationPath 'tools\binutils' -Force"
    if errorlevel 1 (
        echo Error: Failed to extract MIPS binutils
        exit /b 1
    )
    
    del "%TEMP%\mips-binutils.zip"
    echo MIPS binutils installed successfully!
) else (
    echo MIPS binutils already installed.
)
echo.

REM Download and setup base compilers
echo Setting up base compilers...
if not exist "tools\compilers" (
    echo Downloading base compilers package...
    curl -L "https://files.decomp.dev/compilers_latest.zip" -o "%TEMP%\compilers_latest.zip"
    
    echo Extracting base compilers...
    powershell -Command "Expand-Archive -Path '%TEMP%\compilers_latest.zip' -DestinationPath 'tools\compilers' -Force"
    del "%TEMP%\compilers_latest.zip"
) else (
    echo Base compilers already exist.
)
echo.

REM Download and setup PS2 compiler
echo Setting up MWCCPS2 compiler...

REM Define the target directory path
set PS2_ROOT=tools\compilers\PS2
set COMPILER_DIR=%PS2_ROOT%\mwcps2-3.0.1b198-051011
set GC_DLL_PATH=tools\compilers\GC\3.0a5

if not exist "%COMPILER_DIR%" (
    echo Downloading MWCCPS2 compiler...
    
    if not exist "%PS2_ROOT%" mkdir "%PS2_ROOT%"
    
    curl -L "https://github.com/decompme/compilers/releases/download/compilers/mwcps2-3.0.1b198-051011.tar.gz" -o "mwccps2.tar.gz"
    if errorlevel 1 (
        echo Error: Failed to download MWCCPS2 compiler
        exit /b 1
    )
    
    echo Extracting MWCCPS2 compiler...
    if not exist "%COMPILER_DIR%" mkdir "%COMPILER_DIR%"
    
    REM Extract .tar.gz -> .tar
    powershell -Command "& {Add-Type -AssemblyName System.IO.Compression.FileSystem; $source = 'mwccps2.tar.gz'; $dest = 'mwccps2.tar'; $inStream = New-Object System.IO.FileStream($source, [IO.FileMode]::Open); $gzipStream = New-Object System.IO.Compression.GZipStream($inStream, [IO.Compression.CompressionMode]::Decompress); $outStream = New-Object System.IO.FileStream($dest, [IO.FileMode]::Create); $gzipStream.CopyTo($outStream); $outStream.Close(); $gzipStream.Close(); $inStream.Close()}"
    
    REM Extract .tar INTO the PS2 directory
    tar -xf "mwccps2.tar" -C "%COMPILER_DIR%"
    if errorlevel 1 (
        echo Error: Failed to extract MWCCPS2 compiler
        exit /b 1
    )
    
    REM Cleanup temporary files
    del "mwccps2.tar.gz"
    del "mwccps2.tar"

    REM Patch PS2 compiler
    echo Patching PS2 compiler DLLs...
    
    if exist "%GC_DLL_PATH%\lmgr8c.dll" (
        copy /y "%GC_DLL_PATH%\lmgr8c.dll" "%COMPILER_DIR%\"
        copy /y "%GC_DLL_PATH%\lmgr326b.dll" "%COMPILER_DIR%\"
        echo DLLs replaced successfully!
    ) else (
        echo [!] Warning: GC DLLs not found at %GC_DLL_PATH%. Replacement skipped.
    )

    echo MWCCPS2 compiler installed successfully!
) else (
    echo MWCCPS2 compiler already installed.
)
echo.

REM Download and setup objdiff-cli
echo Setting up objdiff-cli...
set OBJDIFF_DIR=tools\objdiff
set OBJDIFF_EXE=%OBJDIFF_DIR%\objdiff-cli.exe

if not exist "%OBJDIFF_EXE%" (
    echo Downloading objdiff-cli for Windows x86_64...
    
    if not exist "%OBJDIFF_DIR%" mkdir "%OBJDIFF_DIR%"
    
    curl -L "https://github.com/encounter/objdiff/releases/download/v3.5.1/objdiff-cli-windows-x86_64.exe" -o "%OBJDIFF_EXE%"
    if errorlevel 1 (
        echo Error: Failed to download objdiff-cli
        exit /b 1
    )
    
    echo objdiff-cli installed successfully!
) else (
    echo objdiff-cli already installed.
)
echo.

REM Check for game binary
echo Setup complete!
echo.
if not exist "disc\SLUS_216.42" (
    echo [!] Next step: Copy SLUS_216.42 from your copy of the game to the 'disc' directory.
    echo     Then build the project by running: python configure.py
) else (
    echo Game binary found! You can now build the project by running: python configure.py
)
echo.

endlocal
