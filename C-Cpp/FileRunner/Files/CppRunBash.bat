@echo off

REM Determine the file type based on the extension
set "file_extension=%~x1"

REM Compile the file
IF /i "%file_extension%"==".c" (
    gcc %1 -o %1.out
) ELSE IF /i "%file_extension%"==".cpp" (
    g++ %1 -o %1.exe
) ELSE (
    echo Unsupported file type. Please provide a valid C or C++ source file.
    exit /b
)

REM Check if the compilation was successful
IF ERRORLEVEL 1 (
    echo Compilation failed. Please check the file for errors.
    exit /b
)

REM Execute the compiled program
IF /i "%file_extension%"==".c" (
    .\%1.out
) ELSE IF /i "%file_extension%"==".cpp" (
    .\%1.exe
)

REM Optionally, pause execution to see the output before closing the window
pause Press any key to exit...
