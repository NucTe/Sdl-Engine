#define SDL_MAIN_HANDLED
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <GL/glew.h>
#include "gameloop.h"
#include "Renderer/OpenGLRenderer.h"

class Window {
public:
    Window();
    ~Window();
    void Run(std::string vertexShaderPath, std::string fragmentShaderPath);
    void CreateWindow(const std::string& title, int width, int height, GameLoop* gameLoop);
    SDL_Window* GetSDLWindow();
private:
    
    SDL_Window* window = nullptr;
    SDL_GLContext glContext = nullptr;
    GameLoop* gameLoop;
    OpenGLRenderer* renderer;
};

#endif
