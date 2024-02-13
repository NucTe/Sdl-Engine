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
  "$(SolutionDir)/deps/glm/",
  "$(SolutionDir)/deps/",
}

files {
  "$(SolutionDir)/deps/imgui/**.cpp",
}

for _, path in ipairs(DepsINC) do
  includedirs { path }
end

include "Core"
include "Game"
include "Engine"
