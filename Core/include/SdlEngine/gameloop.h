#pragma once

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "window.h"

class GameLoop {
public:
    GameLoop();
    virtual ~GameLoop();

    void Run(Window window);

protected:
    virtual void Initialize() = 0;
    virtual void ProcessInput() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(Window window) = 0;
    virtual void Cleanup() = 0;

private:
    bool quit; 
};

#endif