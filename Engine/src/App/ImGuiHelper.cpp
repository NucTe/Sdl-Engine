#include "Engine/App/ImGuiHelper.h"
#include "SdlEngine/window.h"
#include <iostream>

namespace NUCTE_NS {

    ImGuiHelper::ImGuiHelper(){}

    ImGuiHelper::~ImGuiHelper() {
        cleanup();
    }

    void ImGuiHelper::initialize(Window* win) {
        m_win = win;
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        ImGui::StyleColorsDark();

        ImGui_ImplSDL2_InitForOpenGL(win->GetSDLWindow(), win->GetContext());
        ImGui_ImplOpenGL3_Init("#version 330 core");
    }

    void ImGuiHelper::cleanup() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiHelper::newFrame() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(m_win->GetSDLWindow());
        ImGui::NewFrame();
    }

    void ImGuiHelper::render() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiHelper::update() {
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }
    }

    void ImGuiHelper::events(SDL_Event* event) {
        ImGui_ImplSDL2_ProcessEvent(event);
    }

}
