@echo off

REM Set the path to the Visual Studio generator
SET "generator=Visual Studio 17 2022"

REM Set the path to the source and build directories
SET "build=./build"

REM Check if the argument "clean" is provided
IF "%1"=="clean" (
    REM Remove the build directory
    rmdir /s /q "%build%"
    REM Exit the batch file
    exit /b
)

REM Generate the Visual Studio solution using CMake
cmake -G "%generator%" -B "%build%"

REM Build the solution using MSBuild
cmake --build "%build%" --config Release

Pause
