#pragma once

#ifndef GAMELOOP_H
#define GAMELOOP_H

class GameLoop {
public:
    GameLoop();
    virtual ~GameLoop();

    void Run();

protected:
    virtual void Initialize() = 0;
    virtual void ProcessInput() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;

private:
    bool quit;
};

#endif

