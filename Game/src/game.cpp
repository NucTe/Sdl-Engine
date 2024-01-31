#include "gameloop.h"
#include "player.h"

#include "SdlEngine/draw.h"
#include "SdlEngine/texturemanager.h"


MyGame::MyGame() {
}

MyGame::~MyGame() {
    // Cleanup any game-specific resources
}

void MyGame::Initialize() {
    Vector2 playerPosition = { 100.0f, 100.0f };
    Vector2 playerSize = { 50.0f, 50.0f };
    Player* player = new Player(playerPosition, playerSize);
    entityManager.AddEntity(player);
}

void MyGame::ProcessInput() {
    // Implement input processing logic for your game
}

void MyGame::Update(float deltaTime) {
    for (const auto& entity : entityManager.GetEntities()) {
        entity->Update(deltaTime);
    }
}

void MyGame::Render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
    SDL_RenderClear(renderer);

    for (const auto& entity : entityManager.GetEntities()) {
        entity->Render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void MyGame::Cleanup() {
    // Implement cleanup logic for your game
}
