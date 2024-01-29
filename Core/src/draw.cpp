#include "SdlEngine/draw.h"

void Draw::Point(SDL_Renderer* renderer, const Vector2& point, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, static_cast<int>(point.x), static_cast<int>(point.y));
}

void Draw::Line(SDL_Renderer* renderer, const Vector2& start, const Vector2& end, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, static_cast<int>(start.x), static_cast<int>(start.y),
        static_cast<int>(end.x), static_cast<int>(end.y));
}

void Draw::Rectangle(SDL_Renderer* renderer, const Vector2& position, float width, float height, SDL_Color color, bool fill) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = { static_cast<int>(position.x), static_cast<int>(position.y),
                      static_cast<int>(width), static_cast<int>(height) };
    if (fill) {
        SDL_RenderFillRect(renderer, &rect);
    }
    else {
        SDL_RenderDrawRect(renderer, &rect);
    }
}

void Draw::TextureRect(SDL_Renderer* renderer, const std::string& filePath, const Vector2& position, float width, float height) {
    // Implement your logic to draw a texture within a rectangle here
    // You can use the TextureManager to load and draw textures
}

