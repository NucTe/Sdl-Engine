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

#include "Engine/utils.h"

class Window {
public:
    Window();
    ~Window();
    void Run(std::string vertexShaderPath = "", std::string fragmentShaderPath = "");
    void CreateWindow(const std::string& title, int width, int height, bool fullscreen, GameLoop* gameLoop = nullptr);
    void ToggleFullscreen();
    void SetWindowSize(int width, int height);
    int GetScreenWidth();
    int GetScreenHeight();
    SDL_GLContext GetContext() const;


    SDL_Window* GetSDLWindow();

private:

    int screenWidth;
    int screenHeight;
    bool isFullscreen;

    SDL_Window* window = nullptr;
    SDL_GLContext glContext = nullptr;
    GameLoop* gameLoop;
    OpenGLRenderer* renderer;
};

#endif
