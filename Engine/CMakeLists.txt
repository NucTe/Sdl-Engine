# Engine

project(Engine)

file(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp" "src/**/*.cpp")
add_executable(Engine ${ENGINE_SOURCES})

target_include_directories(Engine PUBLIC "include/")
target_include_directories(Engine PUBLIC "../Core/include/")

target_include_directories(Engine PUBLIC ${DEPS_INCLUDE_DIRS})
target_link_libraries(Engine PRIVATE
    Core
    Interface
    opengl32
    glew32
    glew32s
    SDL2
    SDL2main
    SDL2_image
)

target_link_directories(Engine PRIVATE
    "${CMAKE_SOURCE_DIR}/vendors"
)
