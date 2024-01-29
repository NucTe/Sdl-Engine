#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <unordered_map>

class TextureManager {
public:
    static TextureManager& Instance();

    SDL_Texture* LoadTexture(const std::string& filePath);
    void DrawTextureRect(SDL_Renderer* renderer, const std::string& filePath, int x, int y, int width, int height);
    void ClearTextures();

private:
    TextureManager();
    ~TextureManager();

    SDL_Texture* GetDefaultTexture();

    std::unordered_map<std::string, SDL_Texture*> textures;
    SDL_Texture* defaultTexture;
};
