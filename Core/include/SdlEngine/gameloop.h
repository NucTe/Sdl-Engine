#pragma once

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <GL/glew.h>
#include <SDL2/SDL.h>

class Window;

class GameLoop {
public:
    GameLoop();
    virtual ~GameLoop();

    void init(Window *window) { this->window = window; };
    void Run();

protected:
    Window* window = nullptr;
    virtual void Initialize() = 0;
    virtual void ProcessInput() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;

private:
    
    bool quit = false; 
};

#endif