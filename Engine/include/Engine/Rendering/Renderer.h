#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include "SdlEngine/Renderer/OpenGLRenderer.h"
#include "SdlEngine/draw.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "Engine/utils.h"
namespace NUCTE_NS {

    class GameWorld;

    class Renderer {
    public:
        Renderer(SDL_Window* m_window);
        ~Renderer();
        void Render(const GameWorld& gameWorld);

    private:
        SDL_Window* m_Window;
        SDL_GLContext m_GLContext;
        OpenGLRenderer m_OpenGLRenderer;
        Draw m_draw;
    };
}

#endif // RENDERER_H
