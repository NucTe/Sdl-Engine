#include "Engine/App/Imgui/ImGuiHelper.h"
#include "SdlEngine/window.h"
#include <iostream>

namespace NUCTE_NS {

    ImGuiHelper::ImGuiHelper(){}

    ImGuiHelper::~ImGuiHelper() {
        cleanup();
    }

    void ImGuiHelper::initialize(::Window* win) {
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
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiHelper::render() {
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::Render();
        int display_w, display_h;
        SDL_GL_GetDrawableSize(m_win->GetSDLWindow(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }



    void ImGuiHelper::update() {
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            SDL_Window* backup_current_window = SDL_GL_GetCurrentWindow();
            SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
        }
    }

    void ImGuiHelper::events(SDL_Event* event) {
        ImGui_ImplSDL2_ProcessEvent(event);
    }

    ImGuiID ImGuiHelper::GetDockspaceID() const {
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        if (viewport) {
            ImGuiDockNode* dockNode = ImGui::DockBuilderGetNode(viewport->ID);
            if (dockNode) {
                return dockNode->ID;
            }
        }
        return ImGui::GetID("MyDockspace");
    }

    ImGuiID ImGuiHelper::GetDockspaceNodeID(std::string DockID) const {
        ImGuiID dockspaceID = ImGui::GetID(DockID.c_str());
        return dockspaceID;
    }


}
