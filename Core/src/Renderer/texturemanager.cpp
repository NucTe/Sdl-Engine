#include "SdlEngine/Renderer/texturemanager.h"
#include "SdlEngine/Renderer/OpenGLRenderer.h"
#include "stb/stb_image.h"

std::unordered_map<std::string, GLuint> TextureManager::textureMap;
GLuint TextureManager::vaoID = 0;
GLuint TextureManager::vboID = 0;

GLuint TextureManager::CreateTextureID() {
    GLuint texture;
    glGenTextures(1, &texture);
    return texture;
}

GLuint TextureManager::LoadTexture(const std::string& filePath) {
    GLuint texture = CreateTextureID();

    int width, height, channels;
    unsigned char* image = stbi_load(filePath.c_str(), &width, &height, &channels, STBI_rgb_alpha);

    if (!image) {
        std::cerr << "Unable to load image: " << stbi_failure_reason() << std::endl;
    }
    else {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

        stbi_image_free(image);

        textureMap[filePath] = texture;
    }

    return texture;
}

GLuint TextureManager::DrawRect(const std::string& filePath, const glm::vec2& position, int width, int height) {
    GLuint vaoID = OpenGLRenderer::CreateTextureRectVAO(filePath, width, height);
    OpenGLRenderer::DrawTextureRect(vaoID, position, width, height);
    return vaoID;
}

void TextureManager::Clear() {
    for (auto& pair : textureMap) {
        glDeleteTextures(1, &pair.second);
    }
    textureMap.clear();
}
