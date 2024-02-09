#include <GL/glew.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>

#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create a fullscreen SDL window
    SDL_Window* window = SDL_CreateWindow("NucTe-Engine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        0, 0,
        SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (!window) {
        fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
        return -1;
    }

    SDL_DisplayMode currentDisplayMode;
    SDL_GetCurrentDisplayMode(0, &currentDisplayMode);
    int screenWidth = currentDisplayMode.w;
    int screenHeight = currentDisplayMode.h;

    // Set OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Create OpenGL context
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        fprintf(stderr, "Error creating OpenGL context: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        return -1;
    }

    // Initialize GLEW
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        fprintf(stderr, "Error initializing GLEW: %s\n", glewGetErrorString(glewError));
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        return -1;
    }

    // Check if OpenGL 3.3 is supported
    if (!GLEW_VERSION_3_3) {
        fprintf(stderr, "OpenGL 3.3 is not supported!\n");
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        return -1;
    }

    SDL_GL_SetSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    ImGui_ImplOpenGL3_Init("#version 330");
    NUCTE_NS::Renderer renderer(window);
    NUCTE_NS::EntityManager em;
    NUCTE_NS::GameWorld world(em);
    const int targetFrameRate = 60;
    const Uint32 targetFrameTime = 1000 / targetFrameRate;

    Uint32 lastFrameTime = SDL_GetTicks();
    bool running = true;
    while (running) {
        Uint32 currentFrameTime = SDL_GetTicks();
        Uint32 deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                running = false;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();
        ImGui::Begin("Renderer");
        renderer.Render(world, );
        ImGui::End();
        
        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(window);

        Uint32 frameTime = SDL_GetTicks() - currentFrameTime;
        if (frameTime < targetFrameTime) {
            SDL_Delay(targetFrameTime - frameTime);
        }
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
