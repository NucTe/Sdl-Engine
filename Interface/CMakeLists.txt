# Interface

project(Interface)

file(GLOB_RECURSE INTER_SOURCES "src/*.cpp" "src/**/*.cpp")
add_library(Interface STATIC ${INTER_SOURCES})

target_include_directories(Interface PUBLIC include)

target_include_directories(Interface PUBLIC ${DEPS_INCLUDE_DIRS})
# Add any necessary library dependencies and compile options here
