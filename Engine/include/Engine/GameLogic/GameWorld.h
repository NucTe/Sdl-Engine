#pragma once

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>
#include <list>
#include <glm/glm.hpp>


#include "Physics/2d/Physics.h"
#include "Engine/EMS/EntityManager.h"
#include "Engine/utils.h"



namespace NUCTE_NS {

    class Renderer;

    struct Rectangle {
        int id;
        glm::vec2 position;
        float width;
        float height;
        glm::vec4 color;
        PhysicsObject* physicsObject;
    };

    class GameWorld {
    public:
        GameWorld();
        GameWorld(EntityManager& entityManager, Renderer& renderer);
        ~GameWorld();

        GameWorld(const GameWorld& other)
            : entityManager(other.entityManager),
            m_Rend(other.m_Rend),
            RectId(0) {

            for (const auto& entity : other.m_Entities) {
                m_Entities.push_back(new Entity(*entity));
            }

            for (const auto& rect : other.m_Rectangles) {
                m_Rectangles.push_back(rect);
            }
        }


        void Update(float dt);
        void Render();

        void AddRectangle(const glm::vec2& position, float width, float height, const glm::vec4& color, PhysicsObject& physicsObject);
        void RmRectangle(int id);

        const std::list<Rectangle>& GetRectangles() const;

        const std::vector<Entity*>& GetEntities() const;

    private:
        EntityManager& entityManager;
        Renderer& m_Rend;

        int RectId;
        std::list<Rectangle> m_Rectangles;
        std::vector<Entity*> m_Entities;
    };
}

#endif // GAMEWORLD_H
