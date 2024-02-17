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
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }


        ImGui_ImplSDL2_InitForOpenGL(win->GetSDLWindow(), win->GetContext());
        ImGui_ImplOpenGL3_Init("#version 130");
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
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        std::cout << "Display Size: " << io.DisplaySize.x << ", " << io.DisplaySize.y << std::endl; // Debug stateme
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
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
