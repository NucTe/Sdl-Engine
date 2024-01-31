#pragma once

#define SDL_MAIN_HANDLED
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "gameloop.h"

class Window {
public:
    Window(std::string& title, int width, int height, GameLoop* gameLoop);
    ~Window();
    void Run();

    SDL_Renderer* GetRenderer();
private:
    void CreateWindow(const std::string& title, int width, int height);
    SDL_Window* window;
    SDL_Renderer* renderer;
    GameLoop* gameLoop;
};

#endif