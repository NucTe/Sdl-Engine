#pragma once

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl3.h>

#ifndef NUCTE_NS
// NUCTE (NuclearTeam) _NS (_NameSpace)
#define NUCTE_NS NuclearTeam_Namespace 
#endif

namespace NUCTE_NS {

    inline void BeginImGuiFrame(SDL_Window* window) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();
    }

    inline void EndImGuiFrame() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }    
}