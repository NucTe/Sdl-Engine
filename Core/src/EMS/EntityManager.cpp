#include "SdlEngine/EMS/EntityManager.h"

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {
    // Cleanup entities when the manager is destroyed
    for (wEntity* entity : entities) {
        delete entity;
    }
    entities.clear();
}

void EntityManager::AddEntity(wEntity* entity) {
    entities.push_back(entity);
}

void EntityManager::RemoveEntity(wEntity* entity) {
    // Remove and delete the entity
    auto it = std::find(entities.begin(), entities.end(), entity);
    if (it != entities.end()) {
        delete* it;
        entities.erase(it);
    }
}

const std::vector<wEntity*>& EntityManager::GetEntities() const {
    return entities;
}
