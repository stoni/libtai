@echo off

SET CMD=cmake
SET CMD=%CMD% -G"Visual Studio 10"

if not exist build goto make_build_dir

:build
cd build
call %CMD% ..
cd..
goto exit


:make_build_dir
mkdir build
goto build

:exit
