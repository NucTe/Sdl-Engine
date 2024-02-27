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

        Camera GetCamera() {
            return m_Camera;
        }

        float gViewWidth;
        float gViewHeight;
    private:
        Camera m_Camera;
        Application* m_App;
        Window* m_Window;
        static unsigned int m_ShaderProgram;
        ShaderLoader m_shaderLoader;
        GLint m_RectIndexLocation;

        GLuint m_Framebuffer;
        GLuint m_Texture;
        

        void DrawGrid(const Camera& camera, float gridSpacing) {
            glm::vec2 screenTopLeft(0, 0);
            glm::vec2 screenBottomRight(gViewWidth, gViewHeight);

            glm::vec2 worldTopLeft = camera.ScreenToWorld(screenTopLeft);
            glm::vec2 worldBottomRight = camera.ScreenToWorld(screenBottomRight);

            int startX = static_cast<int>(std::floor(worldTopLeft.x / gridSpacing));
            int startY = static_cast<int>(std::floor(worldTopLeft.y / gridSpacing));
            int endX = static_cast<int>(std::ceil(worldBottomRight.x / gridSpacing));
            int endY = static_cast<int>(std::ceil(worldBottomRight.y / gridSpacing));

            for (int x = startX; x <= endX; ++x) {
                glm::vec2 start(x * gridSpacing, worldTopLeft.y);
                glm::vec2 end(x * gridSpacing, worldBottomRight.y);
                Draw::Line(start, end);
            }

            for (int y = startY; y <= endY; ++y) {
                glm::vec2 start(worldTopLeft.x, y * gridSpacing);
                glm::vec2 end(worldBottomRight.x, y * gridSpacing);
                Draw::Line(start, end);
            }
        }




    };
}

#endif 
