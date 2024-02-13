#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include "imgui/imgui.h"

namespace NUCTE_NS {

    class Application;

    class UI {
    public:
        UI(Application* application);
        ~UI();

        void InitImgui();
        void Render();
        void Events(SDL_Event event);

    private:
        SDL_Window* m_Window;
        ImGuiContext* m_ImGuiContext;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    };

}

#endif
