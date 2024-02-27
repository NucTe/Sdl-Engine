#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

#include "Engine/EMS/EntityManager.h"

#include "Engine/App/Imgui/ImGuiHelper.h"
#include "Engine/App/UI.h"

#include "Engine/Input/InputManager.h"

class Window;

namespace NUCTE_NS {

    class ImGuiHelper;
    class Renderer;
    class GameWorld;

    class Application {
    public:
        Application(const std::string& windowTitle, int screenWidth, int screenHeight);
        ~Application();

        void Run();
        double GetDt() const;

        bool IsCtrlPressed() const {
            const Uint8* state = SDL_GetKeyboardState(NULL);
            return state[SDL_SCANCODE_LCTRL] || state[SDL_SCANCODE_RCTRL];
        }

    private:
        ::Window* m_Window;
        SDL_GLContext m_GLContext;
        EntityManager m_Entitym;
        GameWorld* m_World;
        ImGuiHelper* m_IGH;
        UI* m_UI;
        Renderer* m_Renderer;


        float m_ZoomLevel;
        int m_ScreenWidth;
        int m_ScreenHeight;
        bool m_Running;
        double currentTime = 0.0;
        double lastTime = 0.0;

        void Cleanup();
        void HandleEvents();
        void Update();
        void Render();

        
    };

}

#endif