#include "SdlEngine/texturemanager.h"


std::unordered_map<std::string, SDL_Texture*> TextureManager::textureMap;

SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* renderer, const std::string& filePath, int rectWidth, int rectHeight) {
    SDL_Texture* texture = nullptr;

    std::filesystem::path absolutePath = std::filesystem::absolute(filePath);
    std::string file = absolutePath.string();

    SDL_Surface* loadedSurface = IMG_Load(file.c_str());
    if (!loadedSurface) {
        std::cerr << "Unable to load image: " << IMG_GetError() << std::endl;

        SDL_Surface* placeholderSurface = SDL_CreateRGBSurface(0, rectWidth, rectHeight, 32, 0, 0, 0, 0);

        SDL_Rect topLeftRect = { 0, 0, rectWidth / 2, rectHeight / 2 };
        SDL_Rect topRightRect = { rectWidth / 2, 0, rectWidth / 2, rectHeight / 2 };
        SDL_Rect bottomLeftRect = { 0, rectHeight / 2, rectWidth / 2, rectHeight / 2 };
        SDL_Rect bottomRightRect = { rectWidth / 2, rectHeight / 2, rectWidth / 2, rectHeight / 2 };

        SDL_FillRect(placeholderSurface, &topLeftRect, SDL_MapRGBA(placeholderSurface->format, 128, 0, 128, 255));
        SDL_FillRect(placeholderSurface, &topRightRect, SDL_MapRGBA(placeholderSurface->format, 0, 0, 0, 255));
        SDL_FillRect(placeholderSurface, &bottomLeftRect, SDL_MapRGBA(placeholderSurface->format, 0, 0, 0, 255));
        SDL_FillRect(placeholderSurface, &bottomRightRect, SDL_MapRGBA(placeholderSurface->format, 128, 0, 128, 255));

        texture = SDL_CreateTextureFromSurface(renderer, placeholderSurface);
        SDL_FreeSurface(placeholderSurface);
    }
    else {
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
