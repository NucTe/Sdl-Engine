project "Engine"
  kind "ConsoleApp"
  targetdir ("%{wks.location}/bin/Engine/%{cfg.buildcfg}")
  objdir ("%{wks.location}/bin-int/Engine/%{cfg.buildcfg}")

  language "c++"
  cppdialect "c++17"
  
  files {
    "imgui/**.cpp",
    "src/**.cpp",
    "include/**.h"
  }

  includedirs {
    "include/",
    CoreINC
  }

  libdirs {
    DepsLIB
  }

  links {
    "Core.lib",
    "Interface.lib",
  }

  dependson { "Core", "Interface", }