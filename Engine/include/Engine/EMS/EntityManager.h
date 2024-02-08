#pragma once

#include <vector>
#include "Entity.h"

class EntityManager {
public:
    EntityManager();
    ~EntityManager();

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    const std::vector<Entity*>& GetEntities() const;

private:
    std::vector<Entity*> entities;
};
