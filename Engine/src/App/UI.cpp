#include "Engine/App/UI.h"
#include "Engine/App/Imgui/ImGuiHelper.h"
#include "Engine/App/Application.h"

#include "Engine/GameLogic/GameWorld.h"

namespace NUCTE_NS {

    UI::UI(ImGuiHelper* imguiHelper, ::Window* window, Application* app)
        : m_ImGuiHelper(imguiHelper), m_Window(window), m_app(app) {
    }

    UI::~UI() {
    }

    void UI::Render(const GameWorld& gameWorld) {
        m_ImGuiHelper->newFrame();

        ImGui::DockSpaceOverViewport();

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
                m_app->~Application();
            }

            float buttonWidth = 100.0f;
            float spacing = ImGui::GetContentRegionAvail().x - buttonWidth * 2 - ImGui::GetStyle().ItemSpacing.x * 2;

            ImGui::SetCursorPosX(ImGui::GetWindowWidth() - buttonWidth * 2 - spacing);

            if (ImGui::Button("Compile", ImVec2(buttonWidth, 0))) {
            }

            ImGui::SameLine();

            GLuint run_arrow = TextureManager::LoadTexture("assets/run_arrow.png");
            if (ImGui::ImageButton(
                (ImTextureID)(intptr_t)run_arrow,
                ImVec2(buttonWidth, 0),
                ImVec2(0, 0),
                ImVec2(1, 1),
                -1,
                ImVec4(0, 0, 0, 0),
                ImVec4(1, 1, 1, 1)
            )) {
            }

            ImGui::EndMainMenuBar();
        }

        static bool showFileManager = true;
        ImGui::SetNextWindowSize(ImVec2(300, 400), ImGuiCond_FirstUseEver);
        ImGui::Begin("File Manager", &showFileManager);
        ImGui::Text("File Manager UI goes here...");
        ImGui::End();

        ImGui::Begin("Game Viewport");
        ImVec2 viewportSize = ImGui::GetContentRegionAvail();
        glViewport(0, 0, (int)viewportSize.x, (int)viewportSize.y);
        Renderer::Render(gameWorld);
        ImGui::End();

        m_ImGuiHelper->render();
        m_ImGuiHelper->update();

        SDL_GL_SwapWindow(m_Window->GetSDLWindow());
    }

}
