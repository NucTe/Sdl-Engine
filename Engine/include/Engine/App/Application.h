#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"
#include "Engine/EMS/EntityManager.h"
#include "Engine/App/ImGuiHelper.h"


namespace NUCTE_NS {
    class Window;
    class ImGuiHelper;
}

namespace NUCTE_NS {

    class Application {
    public:
        Application(const std::string& windowTitle, int screenWidth, int screenHeight);
        ~Application();

        void Run();

    private:
        Window* m_Window;
        SDL_GLContext m_GLContext;
        Renderer m_Renderer;
        EntityManager m_Entitym;
        GameWorld m_World;
        ImGuiHelper* m_IGH;

        int m_ScreenWidth;
        int m_ScreenHeight;
        bool m_Running;

        void Cleanup();
        void HandleEvents();
        void Update();
        void Render();
    };

}

#endif