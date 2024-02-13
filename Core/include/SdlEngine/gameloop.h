#pragma once

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Window;

class GameLoop {
public:
    GameLoop();
    virtual ~GameLoop();

    void init(Window *window) { this->window = window; };
    void Run(GLuint shaderProgram);

protected:
    Window* window = nullptr;
    virtual void Initialize() = 0;
    virtual void ProcessInput() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;

private:
    static glm::mat4 modelMatrix;
    bool quit = false; 
};

#endif