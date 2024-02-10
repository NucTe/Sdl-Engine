#include "Engine/EMS/EntityManager.h"

namespace NUCTE_NS {
    EntityManager::EntityManager() {}

    EntityManager::~EntityManager() {
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
}

