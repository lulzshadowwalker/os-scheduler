workspace "os-scheduler"
   configurations { "debug", "release" }

project "scheduler"
   kind "ConsoleApp"
   location "src/"
   language "C++"
   cppdialect "C++14"
   targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
   targetname "application"
   objdir "bin-obj/%{cfg.buildcfg}/%{prj.name}"

   files { "src/**.hpp", "src/**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
