# Main

cmake_minimum_required(VERSION 3.10)
project(Sdl-Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(DEPS_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/deps
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/GL
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/nlohmann
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/Physics
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/SDL2/include
)


include_directories(${DEPS_INCLUDE_DIRS})

add_subdirectory(Core)
add_subdirectory(Interface)
add_subdirectory(Engine)





