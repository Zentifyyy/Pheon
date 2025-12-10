project "Pheon"
   kind "StaticLib"
   language "C++"
   cppdialect "C++latest"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "include/**.h", "src/**.cpp", "**.rc", "**.h" }

   includedirs
   {
      "include",
      "../vendor/SDL/include",
      "../vendor/SDL_ttf/include",
   }

   links{
        "SDL",
        "SDL_ttf",
   }

   externalproject "SDL"
   location "../vendor/SDL/VisualC/SDL/"
   kind "StaticLib"
   language "C"

   externalproject "SDL_ttf"
   location "../vendor/SDL_ttf/VisualC/"
   kind "StaticLib"
   language "C"

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
      defines { "WL_DIST" }
      runtime "Release"
      optimize "On"
      symbols "Off"