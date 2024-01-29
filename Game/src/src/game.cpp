#include "gameloop.h"
#include "SdlEngine/draw.h"

MyGame::MyGame() {
}

MyGame::~MyGame() {
    // Cleanup any game-specific resources
}

void MyGame::Initialize() {
    // Implement initialization logic for your game
}

void MyGame::ProcessInput() {
    // Implement input processing logic for your game
}

void MyGame::Update() {
    // Implement game update logic
}

void MyGame::Render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    Vector2 rectPosition = { 400.0f, 100.0f };
    Draw::Rectangle(renderer, rectPosition, 50, 50, { 0, 74, 82, 107 }, false);

    Vector2 trectPosition = { 400.0f, 200.0f };
    Draw::TextureRect(renderer, ". /e.png", trectPosition, 50, 50);

    SDL_RenderPresent(renderer);
}

void MyGame::Cleanup() {
    // Implement cleanup logic for your game
}
