project "Interface"
  kind "StaticLib"
  targetdir ("%{wks.location}/bin/Engine/%{cfg.buildcfg}")
  objdir ("%{wks.location}/bin-int/Engine/%{cfg.buildcfg}")

  language "c++"
  cppdialect "c++17"
  
  files {
    "src/**.cpp",
    "include/**.h"
  }

  includedirs {
    "include/",
    CoreINC,
    EngineINC,
  }

  libdirs {
    DepsLIB
  }

  links {
    "Core"
  }