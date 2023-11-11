#!/bin/bash

# Function to check if g++ is installed
is_gcc_gpp_installed() {
    if command -v gcc > /dev/null 2>&1 && command -v g++ > /dev/null 2>&1; then
        return 1  # Return true (success) if both gcc and g++ are installed
    else
        return 0  # Return false (failure) if either gcc or g++ is not installed
    fi
}

#Function to install Compiler
install_complier() {
    # Opening another script file
    if [ -f "./install/installCompiler.sh" ]; then
        bash ./install/installCompiler.sh "$1"
    else
        echo "Error: CppRunShell.sh not found."
        exit 1
    fi
}

# Function to run Linux-specific commands
run_linux_commands() {
    # Linux-specific commands
    # Opening another script file
    if [ -f "./Files/CppRunShell.sh" ]; then
        bash ./Files/CppRunShell.sh "$1"
    else
        echo "Error: CppRunShell.sh not found."
        exit 1
    fi
}

# Function to run Windows-specific commands
run_windows_commands() {
    # Windows-specific commands (Git Bash or WSL might be available)
    # Opening another script file
    if [ -f "./Files/CppRunBash.bat" ]; then
        bash ./Files/CppRunBash.bat "$1"
    else
        echo "Error: CppRunBash.bat not found."
        exit 1
    fi
}

# Function to run MacOS-specific commands
run_macos_commands()
{
    # macOS-specific commands
    if [ -f "./Files/CppRunShell.sh" ]; then
        bash ./Files/CppRunShell.sh $1
    else
        echo "Error: CppRunShell.sh not found."
        exit 1
    fi
}

# Function to run default commands
run_default_commands() {
    # Opening another script file
    if [ -f "./Files/CppRunWithPy.py" ]; then
        python3 ./Files/CppRunWithPy.py "$1"
    else
        echo "Error: CppRunWithPy.py not found."
        exit 1
    fi
}

run_code()
{
    # Get the operating system type
    os_type=$(uname)
    # Check if g++ is installed and run appropriate commands based on the OS
    case $os_type in
        Linux)
            run_linux_commands "$1"
            ;;
        CYGWIN*|MINGW32*|MSYS*|MINGW*)
            run_windows_commands "$1"
            ;;
        Darwin)
            run_macos_commands "$1"
            ;;
        *)
            run_default_commands "$1"
            ;;
    esac
}

# Check if a gcc gpp is installed
if is_gcc_gpp_installed; then
    install_complier
    exit 1
fi

# Check if a filename argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <C/Cpp file>"
    exit 1
fi

# Check for the existence of the uname command
if command -v uname > /dev/null 2>&1; then
    
    run_code "$1"
    
    read -p "Press Enter to exit..."

    # Delete the compiled executable
    rm "$1.out" || "$1.exe"

else
    echo "Error: uname command not found."
    exit 1
fi
