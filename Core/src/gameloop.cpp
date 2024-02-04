#include "SdlEngine/gameloop.h"
#include <SDL2/SDL.h>
#include "SdlEngine/window.h"

GameLoop::GameLoop() : quit(false) {
    // Initialization logic here
}

GameLoop::~GameLoop() {}

void GameLoop::Run() {
    Initialize();
    SDL_Event event;

    std::cout << "Called" << std::endl;
    std::cin.get();

    Uint32 prevTicks = SDL_GetTicks();
    Uint32 currentTicks;

    while (!quit) {
        currentTicks = SDL_GetTicks();
        float deltaTime = (currentTicks - prevTicks) / 1000.0f;
        prevTicks = currentTicks;


        ProcessInput();
        Update(deltaTime);
        Render();
    }

    Cleanup();
}