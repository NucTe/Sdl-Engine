#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace NUCTE_NS {
    Renderer::Renderer(SDL_Window* window) : m_Window(window) {
    }

    Renderer::~Renderer() {}

    void Renderer::Render(const GameWorld& gameWorld) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        SDL_GL_SwapWindow(m_Window);
    }
}


