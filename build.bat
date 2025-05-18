@echo off
setlocal EnableDelayedExpansion

cls

if exist build (
    echo build directory detected!
    set /p recreate_build_dir=RECREATE BUILD DIRECTORY {Y or N} 

    if /i "!recreate_build_dir!"=="Y" (
        del build
        timeout /t 2 /nobreak >nul
        echo Creating build directory...
        timeout /t 3 /nobreak >nul
        cmake -B build
    ) else if /i "!recreate_build_dir!"=="N" (
        echo Keeping existing build directory...
        timeout /t 2 /nobreak >nul
    ) else (
        echo Invalid input! Please enter Y or N.
        exit /b 1
    )
) else (
    echo build directory not detected!
    timeout /t 3 /nobreak >nul
    echo Creating build directory...
    timeout /t 3 /nobreak >nul
    cmake -B build
)

echo Build folder created!
timeout /t 2 /nobreak >nul
echo Now execute run.bat to build and start the program! 

endlocal