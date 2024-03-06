# Interface

project(Interface)

file(GLOB_RECURSE INTER_SOURCES "src/*.cpp" "src/**/*.cpp")
add_library(Interface STATIC ${INTER_SOURCES})

target_include_directories(Interface PUBLIC include)

target_include_directories(Interface PUBLIC ${DEPS_INCLUDE_DIRS})

add_custom_command(TARGET Interface POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Interface>
        ${CMAKE_SOURCE_DIR}/vendors/
    COMMENT "Copying built lib files to vendors folder"
)
