#pragma once

#ifndef MYGAME_H
#define MYGAME_H

#include "SdlEngine/gameloop.h"

class MyGame : public GameLoop {
public:
    MyGame();
    ~MyGame();

protected:
    virtual void Initialize() override;
    virtual void ProcessInput() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Cleanup() override;
};
#endif