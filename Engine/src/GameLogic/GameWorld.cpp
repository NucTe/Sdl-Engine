#include "Engine/GameLogic/GameWorld.h"

GameWorld::GameWorld(EntityManager& entityManager) : entityManager(entityManager) {
}

GameWorld::~GameWorld() {
}

const std::vector<Entity*>& GameWorld::GetEntities() const {
    return entityManager.GetEntities();
}

void GameWorld::Update() {
}
