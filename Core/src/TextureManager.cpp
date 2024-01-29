#include "SdlEngine/TextureManager.h"

TextureManager& TextureManager::Instance() {
    static TextureManager instance;
    return instance;
}

TextureManager::TextureManager() {
    // Initialize default texture (black and purple)
    SDL_Surface* defaultSurface = SDL_CreateRGBSurface(0, 64, 64, 32, 0, 0, 0, 0);
    SDL_FillRect(defaultSurface, nullptr, SDL_MapRGB(defaultSurface->format, 0, 0, 255));
    SDL_FillRect(defaultSurface, &SDL_Rect{ 0, 0, 32, 32 }, SDL_MapRGB(defaultSurface->format, 0, 0, 0));

    defaultTexture = SDL_CreateTextureFromSurface(renderer, defaultSurface);
    SDL_FreeSurface(defaultSurface);
}

TextureManager::~TextureManager() {
    ClearTextures();
    SDL_DestroyTexture(defaultTexture);
}

SDL_Texture* TextureManager::GetDefaultTexture() {
    return defaultTexture;
}

SDL_Texture* TextureManager::LoadTexture(const std::string& filePath) {
    // ... (unchanged)
}

void TextureManager::DrawTextureRect(SDL_Renderer* renderer, const std::string& filePath, int x, int y, int width, int height) {
    SDL_Texture* texture = textures[filePath];

    if (!texture) {
        // If the texture is not loaded, use the default texture
        texture = GetDefaultTexture();
    }

    SDL_Rect destRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

void TextureManager::ClearTextures() {
    for (auto& pair : textures) {
        SDL_DestroyTexture(pair.second);
    }
    textures.clear();
}
