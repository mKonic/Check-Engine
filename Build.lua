-- premake5.lua
workspace "CheckEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "CheckApp"

   -- Workspace-wide build options for MSVC
   require("cmake")
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group ""
include "CheckApp/Build-App.lua"
group ""
include "CheckCore/Build-Core.lua"
group ""
