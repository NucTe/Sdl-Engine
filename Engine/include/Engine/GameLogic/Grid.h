#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Engine/utils.h"

namespace NUCTE_NS {
    class Grid {
    public:
        Grid(int width, int height, int squareSize);

        void SetSize(int width, int height);
        int GetHeight() const {
            return m_Height;
        }
        int GetWidth() const {
            return m_Width;
        }

        glm::ivec2 WorldToGrid(const glm::vec2& worldPos) const;
        glm::vec2 GridToWorld(const glm::ivec2& gridPos) const;

    private:
        int m_Width;
        int m_Height;
        int m_SquareSize;
    };
}