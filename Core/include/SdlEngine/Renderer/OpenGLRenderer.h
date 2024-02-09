#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include <string>
#include <glm/glm.hpp>
#include "Engine/EMS/Entity.h" // Include necessary headers for game entities
#include "Engine/GameLogic/GameWorld.h" // Include necessary headers for the game world

class OpenGLRenderer {
public:
    OpenGLRenderer();
    ~OpenGLRenderer();

    void Render(const NUCTE_NS::GameWorld& gameWorld); // Render the game world

    static GLuint Initialize(const char* vertexShaderPath, const char* fragmentShaderPath);
    static GLuint CreateShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
    static GLuint CreateRectangleVAO();
    static GLuint CreateTextureRectVAO(const std::string& filePath, int width, int height);

    static GLuint DrawTextureRect(GLuint vaoID, const glm::vec2& position, int width, int height, PhysicsObject* physicsObject);
    static GLuint DrawRectangle(GLuint vaoID, const glm::vec2& position, float width, float height, const glm::vec4& color, bool fill, PhysicsObject* physicsObject);
    static void DrawPoint(const glm::vec2& point, const glm::vec4& color);
    static void DrawLine(const glm::vec2& start, const glm::vec2& end, const glm::vec4& color);

private:
    

    static GLuint shaderProgram;
};

#endif // OPENGLRENDERER_H
