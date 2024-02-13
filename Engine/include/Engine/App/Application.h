#pragma once

#include <string>
#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"
#include "Engine/EMS/EntityManager.h"
#include "Engine/App/Ui.h"

namespace NUCTE_NS {

    class Application {
    public:
        Application(const std::string& windowTitle, int screenWidth, int screenHeight);
        ~Application();

        void Run();

        SDL_Window* GetWindow() const;

    private:
        SDL_Window* m_Window;
        SDL_GLContext m_GLContext;
        Renderer m_Renderer;
        EntityManager m_Entitym;
        GameWorld m_World;
        UI* m_UI;
        bool m_Running;

        void InitializeSDL(const std::string& windowTitle, int screenWidth, int screenHeight);
        void InitializeOpenGL();
        void Cleanup();
        void HandleEvents();
        void Update();
        void Render();
    };

}
