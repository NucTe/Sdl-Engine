#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include "SdlEngine/Renderer/OpenGLRenderer.h"
#include "SdlEngine/Renderer/ShaderLoader.h"

#include "SdlEngine/draw.h"
#include "SdlEngine/window.h"

#include "Engine/Rendering/Camera.h"

#include "Engine/App/Application.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "Engine/utils.h"
namespace NUCTE_NS {

    class GameWorld;

    class Renderer {
    public:
        Renderer(Window* m_Window, Application m_App);
        ~Renderer();
        static GLuint Render(float width, float height, GameWorld gameWorld);

    private:
        static Camera m_Camera;

        Application m_App;
        Window* m_Window;
        static unsigned int m_ShaderProgram;
        ShaderLoader m_shaderLoader;

        void DrawGrid(float width, float height, float zoomLevel) {
            float zoomedWidth = width / zoomLevel;
            float zoomedHeight = height / zoomLevel;

            for (float y = 0; y <= zoomedHeight; y += 1.0f) {
                Draw::Line(glm::vec2(0.0f, y), glm::vec2(zoomedWidth, y), { 239, 239, 240 , 1});
            }

            for (float x = 0; x <= zoomedWidth; x += 1.0f) {
                Draw::Line(glm::vec2(x, 0.0f), glm::vec2(x, zoomedHeight), { 239, 239, 240 , 1});
            }
        }
    };
}

#endif 
