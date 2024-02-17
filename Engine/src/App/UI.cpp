#include "Engine/App/UI.h"
#include "Engine/App/ImGuiHelper.h"

namespace NUCTE_NS {

    UI::UI(ImGuiHelper* imguiHelper, ::Window* window)
        : m_ImGuiHelper(imguiHelper), m_Window(window) {
    }

    UI::~UI() {
        // Cleanup
    }

    void UI::Render() {
        m_ImGuiHelper->newFrame();

        // Create dockspace if it doesn't exist
        if (m_ImGuiHelper->GetDockspaceID() == 0) {
            ImGui::DockBuilderRemoveNode(m_ImGuiHelper->GetDockspaceNodeID("DockSpace"));
            ImGui::DockBuilderAddNode(m_ImGuiHelper->GetDockspaceID(), ImGuiDockNodeFlags_None);
            ImGui::DockBuilderSetNodeSize(m_ImGuiHelper->GetDockspaceNodeID("DockSpace"), ImGui::GetMainViewport()->Size);
            ImGui::DockBuilderFinish(m_ImGuiHelper->GetDockspaceID());
        }

        // Create dockspace that fills the entire viewport
        ImGui::DockSpace(m_ImGuiHelper->GetDockspaceID(), ImVec2(0, 0), ImGuiDockNodeFlags_None);

        // Main menu bar
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("New")) { /* Handle new file */ }
                if (ImGui::MenuItem("Open")) { /* Handle open file */ }
                if (ImGui::MenuItem("Save")) { /* Handle save file */ }
                ImGui::EndMenu();
            }

            // Docks menu
            if (ImGui::BeginMenu("Docks")) {
                if (ImGui::MenuItem("Remove Docks")) {
                    ImGui::DockBuilderRemoveNode(m_ImGuiHelper->GetDockspaceNodeID("DockSpace"));
                    ImGui::DockBuilderFinish(m_ImGuiHelper->GetDockspaceID());
                }
                if (ImGui::MenuItem("Enable Dock View")) {
                    // Rebuild the dockspace node
                    ImGui::DockBuilderRemoveNode(m_ImGuiHelper->GetDockspaceNodeID("DockSpace"));
                    ImGui::DockBuilderAddNode(m_ImGuiHelper->GetDockspaceID(), ImGuiDockNodeFlags_None);
                    ImGui::DockBuilderSetNodeSize(m_ImGuiHelper->GetDockspaceNodeID("DockSpace"), ImGui::GetMainViewport()->Size);
                    ImGui::DockBuilderFinish(m_ImGuiHelper->GetDockspaceID());
                }
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }

        // File manager dock
        static bool showFileManager = true;
        ImGui::SetNextWindowSize(ImVec2(300, 400), ImGuiCond_FirstUseEver);
        ImGui::Begin("File Manager", &showFileManager);

        // File manager UI
        ImGui::Text("File Manager UI goes here...");

        ImGui::End();

        // Debug window
        ImGui::Begin("Debug");
        ImGui::Text("This is some useful debug text.");
        ImGui::End();

        // Render ImGui
        m_ImGuiHelper->render();

        // Update and swap window
        m_ImGuiHelper->update();
        SDL_GL_SwapWindow(m_Window->GetSDLWindow());
    }

}
