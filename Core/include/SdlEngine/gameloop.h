#pragma once

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SDL2/SDL.h>

class GameLoop {
public:
    GameLoop();
    virtual ~GameLoop();

    void Run(SDL_Renderer* renderer);

protected:
    virtual void Initialize() = 0;
    virtual void ProcessInput() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;
    virtual void Cleanup() = 0;

private:
    bool quit;
};

#endif
