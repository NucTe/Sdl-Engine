#pragma once

#include <GL/glew.h>
#include "glm/glm.hpp"
#include <iostream>
#include "../PhysicsObject.h"
#include "../EMS/wEntity.h"
#include "texturemanager.h"

class OpenGLRenderer {
public:
    OpenGLRenderer();
    ~OpenGLRenderer();

    void Initialize(const char* vertexShaderPath, const char* fragmentShaderPath);

    static GLuint CreateShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
    static GLuint CreateRectangleVAO();
    static GLuint CreateTextureRectVAO(const std::string& filePath, int width, int height);

    static void DrawPoint(const glm::vec2& point, const glm::vec4& color);
    static void DrawLine(const glm::vec2& start, const glm::vec2& end, const glm::vec4& color);
    static GLuint DrawRectangle(GLuint vaoID, const glm::vec2& position, float width, float height, const glm::vec4& color, bool fill, PhysicsObject* physicsObject);
    static GLuint DrawTextureRect(GLuint vaoID, const glm::vec2& position, int width, int height, PhysicsObject* physicsObject);
    static GLuint DrawEntity(GLuint vaoID, const wEntity* entity, const glm::vec4& color, bool fill);

private:
    static GLuint shaderProgram;
};