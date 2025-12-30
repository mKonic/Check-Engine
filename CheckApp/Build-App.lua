project "CheckApp"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++23"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
        "../CheckCore/vendor/spdlog/include",
        "../CheckCore/Source"
   }

    links
    {
        "CheckCore"
    }

   targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
   objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

   filter "system:windows"
      systemversion "latest"
      defines { "CE_PLATFORM_WINDOWS" }
      buildoptions { "/utf-8" }
      
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