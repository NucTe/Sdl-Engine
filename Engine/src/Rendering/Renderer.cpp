#include "Engine/Rendering/Renderer.h"
#include <iostream>

Renderer::Renderer(SDL_Window* window) : m_Window(window) {
    m_GLContext = SDL_GL_CreateContext(window);
    if (!m_GLContext) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
    }
    InitializeOpenGL();
}

Renderer::~Renderer() {
}

void Renderer::Render(const GameWorld& gameWorld) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_OpenGLRenderer.Render(gameWorld);
    SDL_GL_SwapWindow(m_Window);
}

void Renderer::InitializeOpenGL() {
    glClearColor(0.45f, 0.55f, 0.60f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
