#include "gameloop.h"
#include "SdlEngine/draw.h"

MyGame::MyGame() {
    // Initialize any game-specific members
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
    Vector2 rectPosition = { 400.0f, 100.0f };
    Draw::Rectangle(renderer, rectPosition, 50, 50, { 0, 74, 82, 107 }, false);

    SDL_RenderPresent(renderer);
}

void MyGame::Cleanup() {
    // Implement cleanup logic for your game
}
