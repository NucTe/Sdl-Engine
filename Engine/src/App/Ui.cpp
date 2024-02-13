#include "Engine/App/Application.h"
#include "Engine/App/Ui.h"

#define IMGUI_IMPL_OPENGL_LOADER_SDL2

#include "imgui/backends/imgui_impl_sdl2.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "imgui/imgui.h"
#include <imgui/imgui_internal.h>

namespace NUCTE_NS {

    UI::UI(Application* application) : m_Window(application->GetWindow()), m_ImGuiContext(nullptr) {
        InitImgui();
    }

    UI::~UI() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext(m_ImGuiContext);
    }

    void UI::InitImgui() {
        IMGUI_CHECKVERSION();
        m_ImGuiContext = ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        ImGui::StyleColorsDark();
        ImGui_ImplSDL2_InitForOpenGL(m_Window, SDL_GL_GetCurrentContext());
        ImGui_ImplOpenGL3_Init("#version 130");
    }

    void UI::Render() {
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(m_Window);
        ImGui::NewFrame();

        ImGui::Begin("Test Window");
        ImGui::Text("This is a test window");
        ImGui::End();

        ImGui::Render();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(m_Window);

    }

    void UI::Events(SDL_Event event) {
        ImGui_ImplSDL2_ProcessEvent(&event);
    }

}
