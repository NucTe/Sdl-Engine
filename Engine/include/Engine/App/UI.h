#pragma once

#include "SdlEngine/window.h"

namespace NUCTE_NS {

    class ImGuiHelper;

    class UI {
    public:
        UI(ImGuiHelper* imguiHelper, ::Window* window);
        ~UI();

        void Render();

    private:
        ImGuiHelper* m_ImGuiHelper;
        ::Window* m_Window;
    };

}
