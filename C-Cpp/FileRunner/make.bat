@echo off

REM Check if a filename argument is provided
IF "%~1"=="" (
    echo Please provide a filename as an argument.
    exit /b
)

REM Compile the C++ file
g++ %1 -o %1.exe

REM Check if the compilation was successful
IF ERRORLEVEL 1 (
    echo Compilation failed. Please check the C++ file for errors.
    exit /b
)

REM Execute the compiled program
.\%1.exe

del %1.exe

REM Optionally, pause execution to see the output before closing the window, Pause with custom msg
pause Press any key to exit...

exit /b

REM Ask the user if they want to delete the compiled executable "%1.exe"
:choice
set /p "delete_choice=Do you want to delete the compiled executable '%1.exe'? (y/n): "
IF /i "%delete_choice%"=="y" (
    echo The '%1.exe' file will be deleted.
    del %1.exe
) ELSE IF /i "%delete_choice%"=="n" (
    echo The '%1.exe' file will be kept.
) ELSE (
    echo Invalid input. Please enter 'y' or 'n'.
    goto choice
)

