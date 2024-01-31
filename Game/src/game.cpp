#include "gameloop.h"
#include "SdlEngine/draw.h"
#include "SdlEngine/texturemanager.h"
#include "SdlEngine/EMS/EntityManager.h"

MyGame::MyGame() {
}

MyGame::~MyGame() {
    // Cleanup any game-specific resources
}

void MyGame::Initialize() {
    
}

void MyGame::ProcessInput() {
    // Implement input processing logic for your game
}

void MyGame::Update() {
    // Implement game update logic
}

void MyGame::Render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    EntityManager entityManager;
    for (const auto& entity : entityManager.GetEntities()) {
        entity->Render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void MyGame::Cleanup() {
    // Implement cleanup logic for your game
}
