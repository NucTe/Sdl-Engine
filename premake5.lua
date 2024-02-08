workspace "Sdl-Engine"
  configurations { "Debug", "Release" }
  architecture "x86_64"
  startproject "Engine"

  flags {
    "MultiProcessorCompile"
  }

DepsINC = "$(SolutionDir)/dependencies/include"
DepsLIB = "$(SolutionDir)/dependencies/lib"

include "Core"
include "Game"
include "Engine"