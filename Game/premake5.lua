project "Game"
  kind "ConsoleApp"
  targetdir ("%{wks.location}/bin/Game/%{cfg.buildcfg}")
  objdir ("%{wks.location}/bin-int/Game/%{cfg.buildcfg}")

  language "c++"
  cppdialect "c++17"
  
  files {
    "src/**.cpp",
    "include/**.h"
  }

  includedirs {
    "include/",
    CoreINC,
    DepsINC
  }

  libdirs {
    DepsLIB
  }

  links {
      "Core"
  }

  filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

  filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

   postbuildcommands {
    '{COPY} %{wks.location}/dependencies/lib/**.dll %{cfg.buildtarget.directory}',
  }