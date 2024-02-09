#include "Engine/Rendering/Renderer.h"
#include "Engine/GameLogic/GameWorld.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace NUCTE_NS {
    Renderer::Renderer(SDL_Window* window) : m_Window(window) {
    }

    Renderer::~Renderer() {}

    void Renderer::Render(const GameWorld& gameWorld) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_OpenGLRenderer.Render(gameWorld);

        NUCTE_NS::BeginImGuiFrame(m_Window);

        ImGui::Begin("Renderer");

        ImVec2 windowSize = ImGui::GetWindowSize();

        ImGui::PushID("Viewport");
        ImDrawList* drawList = ImGui::GetWindowDrawList();
        ImVec2 viewportPos = ImGui::GetCursorScreenPos();
        ImVec2 viewportSize = ImVec2(windowSize.x, windowSize.y);

        drawList->AddLine(ImVec2(viewportPos.x + 100, viewportPos.y + 100), ImVec2(viewportPos.x + 200, viewportPos.y + 200), IM_COL32(255, 255, 255, 255));

        ImGui::End();
        ImGui::PopID();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(m_Window);
    }
}


