-- (c) Spyridon Zervos


workspace "CartesianCoordinatesTest"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    startproject "CartesianCoordinatesTest"

OutputDir = '%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'

group "Core"
    include "Core/Build-Core.lua"
group ""

include "App/Build-App.lua"