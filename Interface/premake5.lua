project "Interface"
  kind "StaticLib"
  targetdir ("%{wks.location}/bin/Interface/%{cfg.buildcfg}")
  objdir ("%{wks.location}/bin-int/Interface/%{cfg.buildcfg}")

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

  filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

  filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

  postbuildcommands {
    "{COPY} %{cfg.buildtarget.relpath} %{wks.location}/vendors"
    }