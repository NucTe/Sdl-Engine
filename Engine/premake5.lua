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
    CoreINC,
    DepsINC
  }

  libdirs {
    DepsLIB
  }

  links {
      "Core",
      "freetype.lib"
  }

  filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

  filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

   postbuildcommands {
    'echo Copying DLL files...',
    '{COPY} %{wks.location}/dependencies/lib/*.dll %{wks.location}/bin/Engine/%{cfg.buildcfg}',
    'echo DLL files copied.'
    }