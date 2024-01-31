#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "EMS/Entity.h"

class Draw {
public:
    // Drawing functions
    static void Point(SDL_Renderer* renderer, const Vector2& point, SDL_Color color);
    static void Line(SDL_Renderer* renderer, const Vector2& start, const Vector2& end, SDL_Color color);
    static void Rectangle(SDL_Renderer* renderer, const Vector2& position, float width, float height, SDL_Color color, bool fill = true);
    static void TextureRect(SDL_Renderer* renderer, const std::string& filePath, const Vector2& position, int width, int height);
    static void Entity(SDL_Renderer* renderer, const wEntity* entity, SDL_Color color, bool fill = true);


private:
    // Private constructor for singleton
    Draw() = delete;

    // Static instance for singleton
    inline static Draw* instance = nullptr;
};

