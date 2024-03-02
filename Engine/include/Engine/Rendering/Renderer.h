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
    class Application;

    class Renderer {
    public:
        Renderer(Window* m_Window, Application* m_App);
        ~Renderer();
        GLuint Render(float width, float height, GameWorld gameWorld);

        float gViewWidth;
        float gViewHeight;
    private:
        Application* m_App;
        Window* m_Window;
        static unsigned int m_ShaderProgram;
        ShaderLoader m_shaderLoader;
        GLint m_RectIndexLocation;

        GLuint m_Framebuffer;
        GLuint m_Texture;
       


    };
}

#endif 
