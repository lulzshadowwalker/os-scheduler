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
      symbols "On"

   filter "configurations:Release"
      optimize "On"

project "tests"
   kind "ConsoleApp"
   location "tests/"
   language "C++"
   cppdialect "C++14"
   targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
   targetname "test"
   objdir "bin-obj/%{cfg.buildcfg}/%{prj.name}"

   files { "tests/**.cpp" }
   includedirs { "src", "%{prj.name}/vendor/cest" }

   filter "configurations:Debug"
      symbols "On"

   filter "configurations:Release"
      optimize "On"

