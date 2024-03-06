# Core

project(Core)

file(GLOB_RECURSE CORE_SOURCES "src/*.cpp" "src/**/*.cpp")
add_library(Core STATIC ${CORE_SOURCES})

target_include_directories(Core PUBLIC "include/")
target_include_directories(Core PUBLIC "../Engine/include/")


target_include_directories(Core PUBLIC ${DEPS_INCLUDE_DIRS})

add_custom_command(TARGET Core POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Core>
        ${CMAKE_SOURCE_DIR}/vendors/
    COMMENT "Copying built lib files to vendors folder"
)
