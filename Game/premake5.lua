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

  links {
    "Core",
  }