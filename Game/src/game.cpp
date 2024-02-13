#include "gameloop.h"
#include "player.h"

#include "SdlEngine/draw.h"
#include "SdlEngine/Renderer/texturemanager.h"
#include "SdlEngine/window.h"
#include "glm/glm.hpp"


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

}

void MyGame::Update(float deltaTime) {
    for (const auto& entity : entityManager.GetEntities()) {
        entity->Update(deltaTime);
    }
}

void MyGame::Render() {

    PhysicsObject physicsObject1(Vector2(200, 200), Vector2(30, 30));
    Vector2 Pos = { 100.0f, 100.0f };

    Draw::Rectangle(glm::vec2(Pos.x, Pos.y), 40, 40, { 0, 0, 255, 0 });

    //for (const auto& entity : entityManager.GetEntities()) {
    //    Draw::Entity(entity, { 255, 0, 0, 0 });
    //}
}

void MyGame::Cleanup() {
    // Implement cleanup logic for your game
}
