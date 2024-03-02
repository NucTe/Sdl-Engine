#pragma once

#include <vector>
#include <glm/glm.hpp>

class Grid {
public:
    Grid(int width, int height, int squareSize);

    void SetSize(int width, int height);

    glm::ivec2 WorldToGrid(const glm::vec2& worldPos) const;
    glm::vec2 GridToWorld(const glm::ivec2& gridPos) const;

private:
    int m_Width;
    int m_Height;
    int m_SquareSize;
};
