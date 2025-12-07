-- premake5.lua
workspace "PheonProject"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "PheonProject"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Pheon/Build-Pheon.lua"
include "PheonProject/Build-Pheon-Project.lua"