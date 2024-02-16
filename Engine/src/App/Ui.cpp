#include "Engine/App/Ui.h"
#include <iostream>

namespace NUCTE_NS {

    UI::UI() : m_ImGuiContext(nullptr) {}

    UI::~UI() {
        for (auto& viewport : m_Viewports) {
            SDL_GL_DeleteContext(viewport.glContext);
        }
        m_Viewports.clear();
        if (m_ImGuiContext) {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext(m_ImGuiContext);
        }
    }

    void UI::InitImgui(SDL_Window* mainWindow) {
        IMGUI_CHECKVERSION();
        m_ImGuiContext = ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        ImGui::StyleColorsDark();
        ImGui_ImplSDL2_InitForOpenGL(mainWindow, SDL_GL_GetCurrentContext());
        ImGui_ImplOpenGL3_Init("#version 330");
    }

    void UI::Render(int Width, int Height) {
        if (m_Viewports.empty()) {
            return;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(m_Viewports[0].window);
        ImGui::NewFrame();

        for (size_t i = 0; i < m_Viewports.size(); ++i) {
            RenderViewport(m_Viewports[i].window, Width, Height);
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void UI::Events(SDL_Event* event) {
        ImGui_ImplSDL2_ProcessEvent(event);
    };

    void UI::RenderViewport(SDL_Window* window, int width, int height) {
        if (window == nullptr)
            return;

        auto it = std::find_if(m_Viewports.begin(), m_Viewports.end(),
            [window](const Viewport& vp) { return vp.window == window; });

        if (it == m_Viewports.end())
            return;

        SDL_GL_MakeCurrent(window, it->glContext);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(width, height));
        ImGui::Begin("Viewport");

        ImGui::End();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    void UI::AddViewport(SDL_Window* window, int width, int height) {
        SDL_GLContext glContext = SDL_GL_CreateContext(window);
        m_Viewports.push_back({ window, glContext });
    }

    void UI::RemoveViewport(SDL_Window* window) {
        auto it = std::find_if(m_Viewports.begin(), m_Viewports.end(),
            [window](const Viewport& vp) { return vp.window == window; });

        if (it != m_Viewports.end()) {
            SDL_GL_DeleteContext(it->glContext);
            m_Viewports.erase(it);
        }
    }

}
