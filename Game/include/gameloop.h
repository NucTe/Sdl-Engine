#pragma once

#ifndef MYGAME_H
#define MYGAME_H

#include "SdlEngine/gameloop.h"
#include <SDL2/SDL_render.h>
#include "SdlEngine/EMS/EntityManager.h"

class MyGame : public GameLoop {
public:
    MyGame();
    ~MyGame();

protected:
    virtual void Initialize() override;
    virtual void ProcessInput() override;
    virtual void Update(float deltaTime) override;
    virtual void Render(SDL_Renderer* renderer) override;
    virtual void Cleanup() override;

private:
    EntityManager entityManager;
};
#endif