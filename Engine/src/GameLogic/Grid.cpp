#include "Engine/GameLogic/Grid.h"

namespace NUCTE_NS {
    Grid::Grid(int width, int height, int squareSize)
        : m_Width(width), m_Height(height), m_SquareSize(squareSize) {}

    void Grid::SetSize(int width, int height) {
        m_Width = width;
        m_Height = height;
    }

    glm::ivec2 Grid::WorldToGrid(const glm::vec2& worldPos) const {
        int x = static_cast<int>(worldPos.x) / m_SquareSize;
        int y = static_cast<int>(worldPos.y) / m_SquareSize;
        return glm::ivec2(x, y);
    }

    glm::vec2 Grid::GridToWorld(const glm::ivec2& gridPos) const {
        float x = static_cast<float>(gridPos.x * m_SquareSize);
        float y = static_cast<float>(gridPos.y * m_SquareSize);
        return glm::vec2(x, y);
    }
}