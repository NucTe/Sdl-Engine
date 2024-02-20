#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include "SdlEngine/Renderer/OpenGLRenderer.h"
#include "SdlEngine/Renderer/ShaderLoader.h"

#include "SdlEngine/draw.h"
#include "SdlEngine/window.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "Engine/utils.h"
namespace NUCTE_NS {

    class GameWorld;

    class Renderer {
    public:
        Renderer(Window* m_Window);
        ~Renderer();
        static GLuint Render(float width, float height, GameWorld gameWorld, OpenGLRenderer* m_OGL);

    private:
        Window* m_Window;
        static unsigned int m_ShaderProgram;
        ShaderLoader m_shaderLoader;
    };
}

#endif 
