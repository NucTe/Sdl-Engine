#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <unordered_map>
#include <iostream>

#include "../PhysicsObject.h"

class TextureManager {
public:
    static GLuint LoadTexture(const std::string& filePath, int rectWidth, int rectHeight);
    static GLuint DrawRect(const std::string& filePath, const glm::vec2& position, int width, int height, PhysicsObject* physicsObject = nullptr);
    static void Clear();

private:
    static std::unordered_map<std::string, GLuint> textureMap;
    static GLuint vaoID;
    static GLuint vboID;
};
