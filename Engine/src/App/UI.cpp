#include "Engine/App/UI.h"
#include "Engine/App/Imgui/ImGuiHelper.h"

namespace NUCTE_NS {

    UI::UI(ImGuiHelper* imguiHelper, ::Window* window)
        : m_ImGuiHelper(imguiHelper), m_Window(window) {
    }

    UI::~UI() {
    }

    void UI::Render() {
        m_ImGuiHelper->newFrame();

        ImGui::DockSpaceOverViewport();

        // Main menu bar
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("New")) {}
                if (ImGui::MenuItem("Open")) {}
                if (ImGui::MenuItem("Save")) {}
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Docks")) {
                if (ImGui::MenuItem("Remove Docks")) {}
                if (ImGui::MenuItem("Enable Dock View")) {}
                ImGui::EndMenu();
            }

            if (ImGui::MenuItem("Exit")) {
                SDL_Quit();
            }

            ImGui::EndMainMenuBar();
        }

        static bool showFileManager = true;
        ImGui::SetNextWindowSize(ImVec2(300, 400), ImGuiCond_FirstUseEver);
        ImGui::Begin("File Manager", &showFileManager);
        ImGui::Text("File Manager UI goes here...");
        ImGui::End();

        ImGui::Begin("Debug");
        ImGui::Text("This is some useful debug text.");
        ImGui::End();

        m_ImGuiHelper->render();

        std::cout << "Swapping window" << std::endl;

        m_ImGuiHelper->update();
      
        SDL_GL_SwapWindow(m_Window->GetSDLWindow());
    }

}
