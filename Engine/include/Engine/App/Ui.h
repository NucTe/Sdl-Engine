#pragma once

#ifndef UI_H
#define UI_H

#include <vector>
#include <SDL2/SDL.h>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_sdl2.h"
#include "imgui/backends/imgui_impl_opengl3.h"

#include "Engine/utils.h"

namespace NUCTE_NS {
    struct Viewport {
        SDL_Window* window;
        SDL_GLContext glContext;
    };

    class UI {
    public:
        UI();
        ~UI();

        void InitImgui(SDL_Window* mainWindow);
        void Events(SDL_Event* event);
        void Render(int Width, int Height);
        
        void AddViewport(SDL_Window* window, int width, int height);
        void RemoveViewport(SDL_Window* window);
        

    private:
        std::vector<Viewport> m_Viewports;
        ImGuiContext* m_ImGuiContext;

        void RenderViewport(SDL_Window* window, int width, int height);
    };

}
#endif