#pragma once

#ifndef UI_H
#define UI_H

#include <vector>
#include <SDL2/SDL.h>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_sdl2.h"
#include "imgui/backends/imgui_impl_opengl3.h"

#include "Engine/utils.h"
#include "Engine/App/Application.h"

namespace NUCTE_NS {
    class Window;
}

namespace NUCTE_NS {
    class ImGuiHelper {
    public:
        ImGuiHelper();
        ~ImGuiHelper();

        void initialize(Window* win);
        void cleanup();

        void newFrame();
        void render();
        void events(SDL_Event* event);


        static void update();
    private:
        Window* m_win;
    };

}
#endif