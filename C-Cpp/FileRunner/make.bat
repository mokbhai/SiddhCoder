@echo off

REM Check if g++ is installed
where gcc > nul 2>&1
if %errorlevel% equ 0 (
    where g++ > nul 2>&1
    if %errorlevel% equ 0 (
        goto :gcc_gpp_installed
    )
)

:gcc_gpp_not_installed
REM Install compiler
if exist .\install\installCompiler.py (
    call :install_python
    call python .\install\installCompiler.py
) else (
    echo Error: installCompiler.py not found.
    exit /b 1
)
goto :eof

:install_python
REM Check if Python is installed
where python > nul 2>&1
if %errorlevel% neq 0 (
    echo Installing Python...
    REM You may replace the URL with the latest Python installer URL
    powershell -Command "(New-Object System.Net.WebClient).DownloadFile('https://www.python.org/ftp/python/3.10.4/python-3.10.4-amd64.exe', 'python-installer.exe')"
    start /wait python-installer.exe /quiet InstallAllUsers=1 PrependPath=1
    del python-installer.exe
    echo Python installed successfully.
) else (
    echo Python is already installed.
)
goto :eof

:gcc_gpp_installed
REM Run Windows-specific commands
if exist .\Files\CppRunBash.bat (
    call .\Files\CppRunBash.bat %1
) else (
    echo Error: CppRunBash.bat not found.
    exit /b 1
)
goto :eof
