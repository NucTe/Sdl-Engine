#pragma once

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <SDL2/SDL.h>

#include "Engine/utils.h"

namespace NUCTE_NS {

    class ImGuiManager {
    public:
        ImGuiManager(SDL_Window* window);
        ~ImGuiManager();

        void BeginFrame();
        void EndFrame();


    private:
        SDL_Window* m_Window;
    };

}
