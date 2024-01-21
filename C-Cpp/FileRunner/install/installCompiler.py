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
        windows2()
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
    mingw_setup_url = "https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe"
    mingw_setup_file = "mingw-get-setup.exe"

    # Download MinGW setup executable
    os.system(f"curl -L -o {mingw_setup_file} {mingw_setup_url}")

    # Check if the file was downloaded successfully
    if os.path.exists(mingw_setup_file):
        print("MinGW setup executable downloaded successfully.")
        os.system("start mingw-get-setup.exe")
        print("Follow the MinGW installation instructions to install GCC and G++.")
        print("Installation complete.")
    else:
        print("Failed to download MinGW setup executable.")
        print("Please check the URL or download it manually.")
        print("Follow the MinGW installation instructions to install GCC and G++.")

def windows2():
    print("Installing GCC GPP...")
    # Download and install MSYS2
    setup_url = "https://github.com/msys2/msys2-installer/releases/download/2023-10-26/msys2-x86_64-20231026.exe"
    setup_file = "msys2.exe"

    # Check if MSYS2 setup executable is already downloaded
    if not os.path.exists(setup_file):
        # Download MSYS2 setup executable
        os.system(f"curl -L -o {setup_file} {setup_url}")
        print("MSYS2 setup executable downloaded successfully.")
    
    # Run MSYS2 installer
    os.system("start msys2.exe")
    
    # Install GCC using pacman within MSYS2 environment
    os.system("msys2.exe -c 'pacman -S mingw-w64-ucrt-x86_64-gcc'")
    
    print("Installation complete.")


def main():
    check_os()

if __name__ == "__main__":
    main()
