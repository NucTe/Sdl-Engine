#pragma once

#ifndef IMGUIHELPER_H
#define IMGUIHELPER_H

#include "SdlEngine/window.h"
#include "SdlEngine/Renderer/texturemanager.h"
#include <vector>
#include <SDL2/SDL.h>
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/backends/imgui_impl_sdl2.h"
#include "imgui/backends/imgui_impl_opengl3.h"

#include "Engine/utils.h"
#include "Engine/App/Application.h"


namespace NUCTE_NS {
    class ImGuiHelper {
    public:
        ImGuiHelper();
        ~ImGuiHelper();

        void initialize(::Window* win);
        void cleanup();

        void newFrame();
        void render();
        void events(SDL_Event* event);

        ImGuiID GetDockspaceID() const;
        ImGuiID GetDockspaceNodeID(std::string DockID) const;

        static void update();
    private:
        ::Window* m_win;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    };

}
#endif