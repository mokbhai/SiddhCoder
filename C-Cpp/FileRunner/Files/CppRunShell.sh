#!/bin/bash

# Determine the file type based on the extension
file_extension="${1##*.}"

# Compile the file
if [ "$file_extension" == "c" ]; then
    gcc "$1" -o "$1.out"
else
    g++ "$1" -o "$1.exe"
fi

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Please check the file for errors."
    exit 1
fi

# Execute the compiled program
if [ "$file_extension" == "c" ]; then
    "./$1.out"
else
    "./$1.exe"
fi

# Delete the compiled executable
# rm "$1.out" || "$1.exe"

# Optionally, pause execution to see the output before closing the terminal
# read -p "Press Enter to exit..."
