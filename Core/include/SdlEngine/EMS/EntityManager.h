#pragma once

#include <vector>
#include "wEntity.h"

class EntityManager {
public:
    EntityManager();
    ~EntityManager();

    void AddEntity(wEntity* entity);
    void RemoveEntity(wEntity* entity);
    const std::vector<wEntity*>& GetEntities() const;

private:
    std::vector<wEntity*> entities;
};
