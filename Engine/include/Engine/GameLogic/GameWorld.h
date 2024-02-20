#pragma once

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>

#include "Engine/EMS/EntityManager.h"
#include "Engine/utils.h"
#include "SdlEngine/Renderer/OpenGLRenderer.h"

namespace NUCTE_NS {
    class Draw;

    class GameWorld {
    public:
        GameWorld(EntityManager& entityManager);
        ~GameWorld();

        GameWorld(const GameWorld& other) : entityManager(other.entityManager) {
            m_Entities = other.m_Entities;
        }

        void Update();
        void Render(OpenGLRenderer* m_OGL);


        const std::vector<Entity*>& GetEntities() const;

    private:
        Draw* m_Draw;
        EntityManager& entityManager;
        std::vector<Entity*> m_Entities;
    };
}


#endif // GAMEWORLD_H
