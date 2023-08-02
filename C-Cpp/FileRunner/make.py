"""
C++ Compiler and Runner

This script compiles and runs a C++ program provided as an argument and
gives the option to delete the compiled executable afterward.
"""

import os
import subprocess
import sys

def compile_and_run_cpp(filename):
    """
    Compile and run the C++ program.

    Args:
        filename (str): Name of the C++ source file.

    Returns:
        str or None: Returns the name of the compiled executable if successful, None otherwise.
    """
    # Remove the ".cpp" extension from the filename
    executable_name = os.path.splitext(filename)[0]

    try:
        # Compile the C++ file
        subprocess.run(["g++", filename, "-o", executable_name], check=True)

        # Check if the compilation was successful
        if not os.path.isfile(executable_name):
            print("Compilation failed. Please check the C++ file for errors.")
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

    if not filename.endswith(".cpp"):
        print("Please provide a valid C++ source file.")
        sys.exit(1)

    # Compile and run the C++ program
    executable_name = compile_and_run_cpp(filename)
    if not executable_name:
        sys.exit(1)

    # Execute the compiled program using the provided filename (without .cpp extension)
    try:
        subprocess.run([executable_name], check=True)
    except subprocess.CalledProcessError as error:
        print(f"Execution failed. Error: {error}")
        sys.exit(1)

    os.remove(executable_name)

    # Ask the user if they want to delete the compiled executable
    # delete_choice = input(f"Do you want to delete the compiled
    #  executable '{executable_name}'? (y/n): ")
    # if delete_choice.lower() == "y":
    #     try:
    #         os.remove(executable_name)
    #         print(f"'{executable_name}' has been deleted.")
    #     except Exception as error:
    #         print(f"Failed to delete '{executable_name}'. Error: {error}")
    # else:
    #     print(f"'{executable_name}' will be kept.")

    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
