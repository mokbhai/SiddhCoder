import os
import subprocess

def compile_and_run_cpp(filename):
    # Remove the ".cpp" extension from the filename
    executable_name = os.path.splitext(filename)[0]

    # Compile the C++ file
    try:
        subprocess.check_output(["g++", filename, "-o", executable_name])
    except subprocess.CalledProcessError as e:
        print(f"Compilation failed. Error: {e}")
        return False

    # Check if the compilation was successful
    if not os.path.isfile(executable_name):
        print("Compilation failed. Please check the C++ file for errors.")
        return False

    return executable_name

def main():
    # Check if a filename argument is provided
    import sys
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
        subprocess.run([executable_name])
    except Exception as e:
        print(f"Execution failed. Error: {e}")
        return False

    os.remove(executable_name)

    # Ask the user if they want to delete the compiled executable
    # delete_choice = input(f"Do you want to delete the compiled executable '{executable_name}'? (y/n): ")
    # if delete_choice.lower() == "y":
    #     try:
    #         os.remove(executable_name)
    #         print(f"'{executable_name}' has been deleted.")
    #     except Exception as e:
    #         print(f"Failed to delete '{executable_name}'. Error: {e}")
    # else:
    #     print(f"'{executable_name}' will be kept.")

    # input("Press Enter to exit...")

if __name__ == "__main__":
    main()
