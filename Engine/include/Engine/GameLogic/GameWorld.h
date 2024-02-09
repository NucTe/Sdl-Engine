#pragma once

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>
#include "Engine/EMS/EntityManager.h"
#include "Engine/utils.h"

namespace NUCTE_NS {
    class GameWorld {
    public:
        GameWorld(EntityManager& entityManager);
        ~GameWorld();

        void Update();

        const std::vector<Entity*>& GetEntities() const;

    private:
        EntityManager& entityManager;
        std::vector<Entity*> m_Entities;
    };
}


#endif // GAMEWORLD_H
