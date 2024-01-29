#include "SdlEngine/gameloop.h"
#include <SDL2/SDL.h>

GameLoop::GameLoop() : quit(false) {
    // Initialization logic here
}

GameLoop::~GameLoop() {
    SDL_Quit();
}

void GameLoop::Run(SDL_Renderer* renderer) {
    Initialize();

    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        ProcessInput();
        Update();
        Render(renderer);
    }

    Cleanup();
}
