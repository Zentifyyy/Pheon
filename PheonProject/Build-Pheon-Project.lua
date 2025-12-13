project "PheonProject"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++latest"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp", "**.rc", "**.h" }

   includedirs{
      "../Pheon/include",
      "../vendor/SDL/include",
      "../vendor/SDL_ttf/include",
      "../vendor/SDL_image/include"
   }

   links{
      "Pheon"
   }

   targetdir ("../output/bin/" .. outputdir .. "/%{prj.name}")
   objdir ("../output/bin-int/" .. outputdir .. "/%{prj.name}")

   filter "system:windows"
      systemversion "latest"
      defines { "WL_PLATFORM_WINDOWS" }
      buildoptions { "/utf-8" }

   filter "configurations:Debug"
      defines { "WL_DEBUG" }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      defines { "WL_RELEASE" }
      runtime "Release"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      kind "WindowedApp"
      defines { "WL_DIST" }
      runtime "Release"
      optimize "On"
      symbols "Off"
