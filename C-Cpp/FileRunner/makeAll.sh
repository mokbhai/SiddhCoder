#!/bin/bash

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

# Check if a filename argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <C/Cpp file>"
    exit 1
fi

# Check for the existence of the uname command
if command -v uname > /dev/null 2>&1; then
    run_default_commands "$1"

    # Delete the compiled executable
    rm "$1.out" || "$1.exe"

else
    echo "Error: uname command not found."
    exit 1
fi
