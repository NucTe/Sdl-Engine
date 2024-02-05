#include "SdlEngine/gameloop.h"
#include <SDL2/SDL.h>


#include "SdlEngine/window.h"
#include "SdlEngine/Renderer/ShaderLoader.h"

GameLoop::GameLoop() : quit(false) {
    // Initialization logic here
}

GameLoop::~GameLoop() {}



void GameLoop::Run(GLuint shaderProgram) {
    Initialize();
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniform4f(glGetUniformLocation(shaderProgram, "color"), 1.0f, 0.0f, 0.0f, 1.0f);
    SDL_Event event;

    Uint32 prevTicks = SDL_GetTicks();
    Uint32 currentTicks;

    while (!quit) {
        currentTicks = SDL_GetTicks();
        float deltaTime = (currentTicks - prevTicks) / 1000.0f;
        prevTicks = currentTicks;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        ProcessInput();
        Update(deltaTime);
        Render();
        SDL_GL_SwapWindow(window->GetSDLWindow());
    }

    Cleanup();
}