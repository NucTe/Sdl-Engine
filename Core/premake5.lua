project "Core"
  kind "StaticLib"
  targetdir ("%{wks.location}/bin/Core/%{cfg.buildcfg}")
  objdir ("%{wks.location}/bin-int/Core/%{cfg.buildcfg}")

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
    EngineINC,
  }

  libdirs {
    DepsLIB
  }

  links {
      "opengl32.lib",
      "glew32.lib",
      "glew32s.lib",
      "SDL2.lib",
      "SDL2main.lib",
      "SDL2_image.lib"
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


CoreINC = "$(SolutionDir)/Core/include/"