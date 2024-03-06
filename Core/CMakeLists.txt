# Core

project(Core)

file(GLOB_RECURSE CORE_SOURCES "src/*.cpp" "src/**/*.cpp")
add_library(Core STATIC ${CORE_SOURCES})

target_include_directories(Core PUBLIC "include/")
target_include_directories(Core PUBLIC "../Engine/include/")


target_include_directories(Core PUBLIC ${DEPS_INCLUDE_DIRS})
# Add any necessary library dependencies and compile options here
