#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"

#include "SdlEngine/draw.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

namespace NUCTE_NS {
    unsigned int Renderer::m_ShaderProgram = 0;

    Renderer::Renderer(Window* window) : m_Window(window) {
        

        m_ShaderProgram = m_shaderLoader.CreateShaderProgram("./assets/shaders/test.vert", "./assets/shaders/test.frag");
        std::cout << m_ShaderProgram << std::endl;
        glUseProgram(m_ShaderProgram);
    }

    Renderer::~Renderer() {
        glDeleteProgram(m_ShaderProgram);
    }

    GLuint Renderer::Render(float width, float height, GameWorld gameWorld) {
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
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        gameWorld.test();
        GLuint colorLocation = glGetUniformLocation(m_ShaderProgram, "rectColors");
        for (const auto& rect : gameWorld.GetRectangles()) {
            glUniform4fv(colorLocation, 1, glm::value_ptr(rect.color));
            Draw::Rectangle(rect.position, rect.width, rect.height);
        }
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return texture;
    }
}
