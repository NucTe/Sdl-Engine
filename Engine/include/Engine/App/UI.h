#pragma once

#include "SdlEngine/window.h"

namespace NUCTE_NS {

    class ImGuiHelper;
    class Application;
    class GameWorld;

    class UI {
    public:
        UI(ImGuiHelper* imguiHelper, ::Window* window, Application* app);
        ~UI();

        void Render(const GameWorld& gameWorld);

    private:
        Application* m_app;
        ImGuiHelper* m_ImGuiHelper;
        ::Window* m_Window;
    };

}
