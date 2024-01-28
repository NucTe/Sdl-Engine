#include "SdlEngine/gameloop.h"
#include <SDL2/SDL.h>

GameLoop::GameLoop() : quit(false){
}

GameLoop::~GameLoop() {
    SDL_Quit();
}

void GameLoop::Run() {
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
        Render();
    }

    Cleanup();
}
