workspace "os-scheduler"
   configurations { "debug", "release" }

project "scheduler"
   kind "ConsoleApp"
   location "src/"
   language "C++"
   cppdialect "C++14"
   targetdir "build/bin/%{cfg.buildcfg}/%{prj.name}"
   targetname "application"
   objdir "build/bin-obj/%{cfg.buildcfg}/%{prj.name}"

   files { "src/**.hpp", "src/**.cpp" }

   filter "configurations:Debug"
      symbols "On"
      defines { "DEBUG" }
      postbuildcommands { "%{cfg.buildtarget.relpath}", "{COPYFILE} %{cfg.buildtarget.relpath} ../%{prj.name}" } --  NOTE: run the application

   filter "configurations:Release"
      optimize "On"

project "tests"
   kind "ConsoleApp"
   location "tests/"
   language "C++"
   cppdialect "C++14"

   local targetDir =  "build/bin/%{cfg.buildcfg}/%{prj.name}"
   local targetName =  "test"

   targetdir(targetDir)
   targetname(targetName)
   objdir "build/bin-obj/%{cfg.buildcfg}/%{prj.name}"

   files { "tests/**.cpp", "src/**.cpp" }
   removefiles { "src/main.cpp" }
   includedirs { "src", "vendor/cest" }
   postbuildcommands { "%{cfg.buildtarget.relpath}" } --  NOTE: run the tests

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      optimize "On"

