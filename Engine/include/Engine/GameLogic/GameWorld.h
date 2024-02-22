#pragma once

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>

#include "SdlEngine/draw.h"

#include "Engine/EMS/EntityManager.h"
#include "Engine/utils.h"

class OpenGLRenderer;
class PhysicsObject;

namespace NUCTE_NS {

    struct Rectangle {
        glm::vec2 position;
        float width;
        float height;
        glm::vec4 color;
        PhysicsObject* physicsObject;
    };

    class GameWorld {
    public:
        GameWorld(EntityManager& entityManager);
        ~GameWorld();

        GameWorld(const GameWorld& other) : entityManager(other.entityManager) {
            m_Entities = other.m_Entities;
        }

        void Update(float dt);
        void Render();

        void AddRectangle(const glm::vec2& position, float width, float height, const glm::vec4& color, PhysicsObject& physicsObject);

        void test();

        const std::vector<Rectangle>& GetRectangles() const;

        const std::vector<Entity*>& GetEntities() const;

    private:
        OpenGLRenderer* m_OGL;
        EntityManager& entityManager;

        std::vector<Rectangle> m_Rectangles;
        std::vector<Entity*> m_Entities;
    };
}


#endif // GAMEWORLD_H
