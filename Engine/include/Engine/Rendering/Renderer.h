#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "Engine/GameLogic/GameWorld.h"
#include "SdlEngine/Renderer/OpenGLRenderer.h"

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    void Render(const GameWorld& gameWorld);

private:
    SDL_Window* m_Window;
    SDL_GLContext m_GLContext;
    OpenGLRenderer m_OpenGLRenderer;

    void InitializeOpenGL();
};

#endif // RENDERER_H
