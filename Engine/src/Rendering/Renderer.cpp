#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace NUCTE_NS {
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
            void main() {
                FragColor = vec4(1.0, 1.0, 1.0, 1.0); // White color
            }
        )";

        m_ShaderProgram = m_shaderLoader.CreateShaderProgram(vertexShaderSource, fragmentShaderSource, true);
        glUseProgram(m_ShaderProgram);
    }

    Renderer::~Renderer() {
        glDeleteProgram(m_ShaderProgram);
    }

    void Renderer::Render(const GameWorld& gameWorld) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float vertices[] = {
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.5f,  0.5f,
            -0.5f,  0.5f 
        };

        GLuint vao, vbo;
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);

    }
}
