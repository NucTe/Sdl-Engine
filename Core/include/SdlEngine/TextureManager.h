#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <unordered_map>

class TextureManager {
public:
    static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const std::string& filePath, int rectWidth, int rectHeight);
    static void Draw(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect& sourceRect, const SDL_Rect& destRect);
    static void Clear();

private:
    static std::unordered_map<std::string, SDL_Texture*> textureMap;
};
