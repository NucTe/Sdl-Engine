#include "SdlEngine/texturemanager.h"

std::unordered_map<std::string, SDL_Texture*> TextureManager::textureMap;

SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* renderer, const std::string& filePath, int rectWidth, int rectHeight) {
    SDL_Texture* texture = nullptr;

    // Try to load the image
    SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
    if (!loadedSurface) {
        // Handle the case where loading the image fails
        std::cerr << "Unable to load image: " << IMG_GetError() << std::endl;

        // Create a placeholder surface for the entire area
        SDL_Surface* placeholderSurface = SDL_CreateRGBSurface(0, rectWidth, rectHeight, 32, 0, 0, 0, 0);

        // Create rectangles for each quadrant
        SDL_Rect topLeftRect = { 0, 0, rectWidth / 2, rectHeight / 2 };
        SDL_Rect topRightRect = { rectWidth / 2, 0, rectWidth / 2, rectHeight / 2 };
        SDL_Rect bottomLeftRect = { 0, rectHeight / 2, rectWidth / 2, rectHeight / 2 };
        SDL_Rect bottomRightRect = { rectWidth / 2, rectHeight / 2, rectWidth / 2, rectHeight / 2 };

        // Fill each quadrant with the appropriate color
        SDL_FillRect(placeholderSurface, &topLeftRect, SDL_MapRGBA(placeholderSurface->format, 128, 0, 128, 255));
        SDL_FillRect(placeholderSurface, &topRightRect, SDL_MapRGBA(placeholderSurface->format, 0, 0, 0, 255));
        SDL_FillRect(placeholderSurface, &bottomLeftRect, SDL_MapRGBA(placeholderSurface->format, 0, 0, 0, 255));
        SDL_FillRect(placeholderSurface, &bottomRightRect, SDL_MapRGBA(placeholderSurface->format, 128, 0, 128, 255));

        // Convert the placeholder surface to a texture
        texture = SDL_CreateTextureFromSurface(renderer, placeholderSurface);
        SDL_FreeSurface(placeholderSurface);
    }
    else {
        // Convert the loaded surface to a texture
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
    }

    return texture;
}



void TextureManager::Draw(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect& sourceRect, const SDL_Rect& destRect) {
    SDL_RenderCopy(renderer, texture, &sourceRect, &destRect);
}

void TextureManager::Clear() {
    for (auto& pair : textureMap) {
        SDL_DestroyTexture(pair.second);
    }
    textureMap.clear();
}
