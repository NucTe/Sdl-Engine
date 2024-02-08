#include "Engine/EMS/EntityManager.h"

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {
    // Cleanup entities when the manager is destroyed
    for (Entity* entity : entities) {
        delete entity;
    }
    entities.clear();
}

void EntityManager::AddEntity(Entity* entity) {
    entities.push_back(entity);
}

void EntityManager::RemoveEntity(Entity* entity) {
    auto it = std::find(entities.begin(), entities.end(), entity);
    if (it != entities.end()) {
        delete* it;
        entities.erase(it);
    }
}

const std::vector<Entity*>& EntityManager::GetEntities() const {
    return entities;
}
