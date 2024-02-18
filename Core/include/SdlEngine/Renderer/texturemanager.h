#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <unordered_map>
#include <iostream>


class TextureManager {
public:
    static GLuint LoadTexture(const std::string& filePath);
    static GLuint DrawRect(const std::string& filePath, const glm::vec2& position, int width, int height);
    static void Clear();

private:
    static GLuint CreateTextureID();

    static std::unordered_map<std::string, GLuint> textureMap;
    static GLuint vaoID;
    static GLuint vboID;
};
