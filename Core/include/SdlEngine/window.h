#pragma once

#define SDL_MAIN_HANDLED
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include "gameloop.h"

class Window {
public:
    Window(const std::string& title, int width, int height, GameLoop* gameLoop);
    ~Window();
    void Run();

    SDL_Renderer* GetRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    GameLoop* gameLoop;
};

#endif