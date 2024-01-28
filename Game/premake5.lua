project "Game"
  kind "ConsoleApp"
  
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


   postbuildcommands {
    '{COPY} %{wks.location}/dependencies/lib/SDL2.dll %{cfg.buildtarget.directory}',
  }