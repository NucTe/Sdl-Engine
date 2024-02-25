#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include "SdlEngine/Renderer/OpenGLRenderer.h"
#include "SdlEngine/Renderer/ShaderLoader.h"

#include "SdlEngine/draw.h"
#include "SdlEngine/window.h"

#include "Engine/Rendering/Camera.h"


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
        Camera m_Camera;
        Application* m_App;
        Window* m_Window;
        static unsigned int m_ShaderProgram;
        ShaderLoader m_shaderLoader;
        GLint m_RectIndexLocation;

        

        void DrawGrid(float width, float height, float zoomLevel) {
            float zoomedWidth = width / zoomLevel;
            float zoomedHeight = height / zoomLevel;

            glUniform1i(m_RectIndexLocation, -1);

            for (float y = 0; y <= zoomedHeight; y += 1.0f) {
                Draw::Line(glm::vec2(0.0f, y), glm::vec2(zoomedWidth, y));
            }

            for (float x = 0; x <= zoomedWidth; x += 1.0f) {
                Draw::Line(glm::vec2(x, 0.0f), glm::vec2(x, zoomedHeight));
            }
        }
    };
}

#endif 
