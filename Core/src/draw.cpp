#include "SdlEngine/draw.h"
#include "SdlEngine/texturemanager.h"

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

void Draw::TextureRect(SDL_Renderer* renderer, const std::string& filePath, const Vector2& position, int width, int height) {
    SDL_Texture* texture = TextureManager::LoadTexture(renderer, filePath, width, height);
    if (!texture) {
        // Handle the case where texture loading fails
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect rect = { static_cast<int>(position.x), static_cast<int>(position.y),
                          static_cast<int>(width), static_cast<int>(height) };
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 128, 0, 128, 255);
        SDL_RenderDrawRect(renderer, &rect);

        return;
    }

    SDL_Rect sourceRect = { 0, 0, static_cast<int>(width), static_cast<int>(height) };
    SDL_Rect destRect = { static_cast<int>(position.x), static_cast<int>(position.y),
                          static_cast<int>(width), static_cast<int>(height) };

    TextureManager::Draw(renderer, texture, sourceRect, destRect);
}

void Draw::Entity(SDL_Renderer* renderer, const wEntity* entity, SDL_Color color, bool fill) {
    Vector2 position = entity->GetPosition();
    Vector2 size = entity->GetSize();

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = { static_cast<int>(position.x), static_cast<int>(position.y),
                      static_cast<int>(size.x), static_cast<int>(size.y) };

    if (fill) {
        SDL_RenderFillRect(renderer, &rect);
    }
    else {
        SDL_RenderDrawRect(renderer, &rect);
    }
}