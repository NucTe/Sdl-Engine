#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "Engine/App/ImGuiManager.h"
#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"
#include "Engine/EMS/EntityManager.h"

namespace NUCTE_NS {

    class Application {
    public:
        Application(const std::string& windowTitle, int screenWidth, int screenHeight);
        ~Application();

        void Run();

    private:
        SDL_Window* m_Window;
        SDL_GLContext m_GLContext;
        Renderer m_Renderer;
        EntityManager m_em;
        GameWorld m_world;
        ImGuiManager m_ImGuiManager;
        bool m_Running;

        void InitializeSDL(const std::string& windowTitle, int screenWidth, int screenHeight);
        void InitializeOpenGL();
        void Cleanup();
        void HandleEvents();
        void Update();
        void Render();
    };

}
