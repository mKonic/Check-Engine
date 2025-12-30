project "CheckCore"
   kind "SharedLib"
   language "C++"
   cppdialect "C++23"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "On"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
      "vendor/spdlog/include"
   }


   targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
   objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

   filter "system:windows"
      systemversion "latest"
      defines { "CE_PLATFORM_WINDOWS", "CE_BUILD_DLL" }
      buildoptions { "/utf-8" }

      postbuildcommands 
      {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/CheckApp")
      }

   filter "configurations:Debug"
      defines { "CE_DEBUG" }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      defines { "CE_RELEASE" }
      runtime "Release"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      kind "WindowedApp"
      defines { "CE_DIST" }
      runtime "Release"
      optimize "On"
      symbols "Off"