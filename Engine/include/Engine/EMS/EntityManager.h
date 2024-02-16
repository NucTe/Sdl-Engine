#pragma once

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include "Entity.h"

namespace NUCTE_NS {
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

}
#endif 