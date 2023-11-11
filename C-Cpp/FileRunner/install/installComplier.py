import platform
import os

def check_os():
    os_type = platform.system()

    if os_type == "Linux":
        print("Linux detected")
        linux()
    elif os_type == "Darwin":
        print("macOS detected")
        macos()
    elif os_type == "Windows":
        print("Windows detected")
        windows()
    else:
        print("Unknown operating system")

def linux():
    print("Installing GCC GPP Clang...")
    # Install GCC and G++
    os.system("sudo apt-get update")
    os.system("sudo apt-get install build-essential")
    # Install Clang
    os.system("sudo apt-get install clang")
    print("Installation complete.")

def macos():
    print("Installing GCC GPP Clang...")
    # Install Xcode Command Line Tools (includes GCC and Clang)
    os.system("xcode-select --install")
    print("Installation complete.")

def windows():
    print("Installing GCC GPP Clang...")
    # Download and install MinGW for GCC and G++
    os.system("wget -O mingw-get-setup.exe https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download")
    os.system("start mingw-get-setup.exe")
    print("Follow the MinGW installation instructions to install GCC and G++.")
    print("Installation complete.")

def windows2():
    print("Installing GCC GPP Clang...")
    # Download and install MinGW for GCC and G++
    os.system("mingw-get install gcc g++")
    # Download and install LLVM for Clang
    os.system("choco install llvm")
    print("Installation complete.")

def main():
    check_os()

if __name__ == "__main__":
    main()
