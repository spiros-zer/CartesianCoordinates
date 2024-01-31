:: (c) Spyridon Zervos


@echo off
pushd ..
external\premake\premake5.exe --file=premake5.lua vs2022
popd

pause