-- premake5.lua
workspace "VulkanTutorial"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "App"

   -- Workspace-wide build options for MSVC
   require("cmake")
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group ""

include "App/Build-App.lua"