workspace "Sdl-Engine"
configurations { "Debug", "Release" }
architecture "x86_64"
startproject "Engine"

flags {
  "MultiProcessorCompile"
}

DepsLIB = "$(SolutionDir)/vendors"
EngineINC = "$(SolutionDir)/Engine/include"


DepsINC = {
  "$(SolutionDir)/deps/SDL2/include",
  "$(SolutionDir)/deps/Physics/include",
  "$(SolutionDir)/deps/glm/",
  "$(SolutionDir)/deps/",
}

files {
  "$(SolutionDir)/deps/imgui/**.cpp",
}

for _, path in ipairs(DepsINC) do
  includedirs { path }
end

local vendorPath = "$(SolutionDir)/vendors"
local targetDir = path.join(vendorPath, "DLLs")
postbuildcommands {
  "{COPY} %{cfg.buildtarget.directory}/*.dll " .. targetDir
}

prebuildcommands {
  "{COPY} " .. targetDir .. "/*.dll %{cfg.buildtarget.directory}"
}

include "Core"
include "Interface"
include "Engine"
