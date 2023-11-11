"""
C++ Compiler and Runner

This script compiles and runs a C++ program provided as an argument and
gives the option to delete the compiled executable afterward.
"""
import os
import subprocess
import sys

def compile_and_run(filename):
    """
    Compile and run the C or C++ program.

    Args:
        filename (str): Name of the source file.

    Returns:
        str or None: Returns the name of the compiled executable if successful, None otherwise.
    """
    # Remove the file extension from the filename
    executable_name = filename

    # Determine the file type based on the extension
    file_extension = os.path.splitext(filename)[1]
    if file_extension == ".c":
        compiler = "gcc"
        executable_name = filename + ".out"
    elif file_extension == ".cpp":
        compiler = "g++"
    else:
        print("Unsupported file type. Please provide a valid C or C++ source file.")
        return None

    try:
        # Compile the file
        subprocess.run([compiler, filename, "-o", executable_name], check=True)

        # Check if the compilation was successful
        if not os.path.isfile(executable_name):
            print("Compilation failed. Please check the source file for errors.")
            return None

        return executable_name

    except subprocess.CalledProcessError as error:
        print(f"Compilation failed. Error: {error}")
        return None

def main():
    """
    Main function to execute the script.
    """
    # Check if a filename argument is provided
    if len(sys.argv) < 2:
        print("Please provide a filename as an argument.")
        sys.exit(1)

    filename = sys.argv[1]

    # Compile and run the program
    executable_name = compile_and_run(filename)
    if not executable_name:
        sys.exit(1)

    # Execute the compiled program
    try:
        subprocess.run(["./" + executable_name], check=True)
    except subprocess.CalledProcessError as error:
        print(f"Execution failed. Error: {error}")
        sys.exit(1)

if __name__ == "__main__":
    main()
