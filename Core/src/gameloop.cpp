#include "SdlEngine/gameloop.h"
#include <SDL2/SDL.h>

GameLoop::GameLoop() : quit(false) {
    // Initialization logic here
}

GameLoop::~GameLoop() {}

void GameLoop::Run(Window *window) {
    Initialize();
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
        Render(window);
    }

    Cleanup();
}
