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


CoreINC = "$(SolutionDir)/Core/include/"