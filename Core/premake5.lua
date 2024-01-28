project "Core"
  kind "StaticLib"
  
  language "c++"
  cppdialect "c++17"
  
  files {
    "src/**.cpp",
    "src/**.c",
    "include/**.h"
  }

  includedirs {
    "include/",
    DepsINC,
  }

  libdirs {
    DepsLIB
  }

  links {
      "SDL2.lib",
      "SDL2main.lib"
  }


CoreINC = "$(SolutionDir)/Core/include/"