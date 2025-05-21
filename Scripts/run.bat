@echo off

set "path_to_main=build\bin\Debug\ParticleSimulation.exe"

echo Building the project...
cmake --build build

if exist "%path_to_main%" (
    echo main.exe found!
    timeout /t 1 /nobreak >nul
    echo Running main.exe...
    timeout /t 1 /nobreak >nul
    start cmd /k "%path_to_main%"
) else (
    echo Path to main is set to %path_to_main%
    echo main.exe not found! Check the value of the path_to_main variable in run.bat
)