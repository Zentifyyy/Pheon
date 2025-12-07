@echo off

pushd ..
vendor\bin\premake\Windows\premake5.exe --file=Build-Example-Project.lua vs2022
popd
pause