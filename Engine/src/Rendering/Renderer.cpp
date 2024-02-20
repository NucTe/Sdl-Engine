#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"

#include "SdlEngine/draw.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

namespace NUCTE_NS {
    unsigned int Renderer::m_ShaderProgram = 0;

    Renderer::Renderer(Window* window) : m_Window(window) {
        const char* vertexShaderSource = R"(
            #version 330 core
            layout (location = 0) in vec2 aPosition;
            void main() {
                gl_Position = vec4(aPosition, 0.0, 1.0);
            }
        )";

        const char* fragmentShaderSource = R"(
            #version 330 core
            out vec4 FragColor;
            uniform float time; // Time uniform for color modulation
            void main() {
                float colorR = (sin(time) + 1.0) / 2.0; // Calculate the color component based on sine wave
                FragColor = vec4(colorR, 1.0 - colorR, 0.5, 1.0); // Use the color component for red, green, and blue channels
            }
        )";

        m_ShaderProgram = m_shaderLoader.CreateShaderProgram(vertexShaderSource, fragmentShaderSource, true);
        std::cout << m_ShaderProgram << std::endl;
        glUseProgram(m_ShaderProgram);
    }

    Renderer::~Renderer() {
        glDeleteProgram(m_ShaderProgram);
    }

    GLuint Renderer::Render(float width, float height, GameWorld gameWorld, OpenGLRenderer* m_OGL) {
        GLuint framebuffer;
        glGenFramebuffers(1, &framebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

        GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        if (status != GL_FRAMEBUFFER_COMPLETE) {
            std::cout << "Framebuffer is not complete! Status: " << status << std::endl;
            glDeleteFramebuffers(1, &framebuffer);
            glDeleteTextures(1, &texture);
            return 0;
        }

        float time = SDL_GetTicks() / 1000.0f;
        glUniform1f(glGetUniformLocation(m_ShaderProgram, "time"), time);

        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        gameWorld.Render(m_OGL);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return texture;
    }
}
