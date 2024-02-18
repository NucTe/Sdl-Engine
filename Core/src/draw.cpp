#include "SdlEngine/draw.h"
#include "SdlEngine/Renderer/texturemanager.h"
#include "SdlEngine/Renderer/OpenGLRenderer.h"

void Draw::Point(const glm::vec2& point, const glm::vec4& color) {
    OpenGLRenderer::DrawPoint(point, color);
}

void Draw::Line(const glm::vec2& start, const glm::vec2& end, const glm::vec4& color) {
    OpenGLRenderer::DrawLine(start, end, color);
}

void Draw::Rectangle(const glm::vec2& position, float width, float height, const glm::vec4& color, bool fill) {
    GLuint vaoID = OpenGLRenderer::CreateRectangleVAO();
    OpenGLRenderer::DrawRectangle(vaoID, position, width, height, color, fill);
    glDeleteVertexArrays(1, &vaoID);
        
}


void Draw::TextureRect(const std::string& filePath, const glm::vec2& position, int width, int height) {
    GLuint vaoID = OpenGLRenderer::CreateTextureRectVAO(filePath, width, height);
    OpenGLRenderer::DrawTextureRect(vaoID, position, width, height);
    glDeleteVertexArrays(1, &vaoID);
}
