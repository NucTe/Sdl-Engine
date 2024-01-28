#include "SdlEngine/window.h"
#include <iostream>

Window::Window(const std::string& title, int width, int height, GameLoop* gameLoop)
    : gameLoop(gameLoop), window(nullptr)
{
    if (!gameLoop) {
        std::cerr << "Error: GameLoop instance not provided to Window constructor." << std::endl;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Unable to create window: " << SDL_GetError() << std::endl;
    }
}


void Window::Run() {
    if (gameLoop) {
        gameLoop->Run();
    }
    else {
        std::cerr << "Error: GameLoop instance not provided to Window." << std::endl;
    }
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}