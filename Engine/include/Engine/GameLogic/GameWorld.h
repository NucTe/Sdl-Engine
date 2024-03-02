#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <list>
#include <glm/glm.hpp>
#include <vector> // Added include for std::vector

#include "Engine/EMS/EntityManager.h"
#include "Engine/GameLogic/Grid.h"
#include "Engine/GameLogic/Camera.h"
#include "Physics/2d/Physics.h"

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
        GameWorld(EntityManager& entityManager, Renderer& renderer);
        ~GameWorld();

        void Update(float dt);

        void AddRectangle(const glm::vec2& position, float width, float height, const glm::vec4& color, PhysicsObject& physicsObject);
        void RmRectangle(int id);

        const std::list<Rectangle>& GetRectangles() const;
        Grid& GetGrid();

        Camera GetCamera() {
            return m_Camera;
        }

        const std::vector<Entity*>& GetEntities() const {
            return m_Entities;
        }

    private:
        EntityManager& entityManager;
        Renderer& m_Rend;
        Grid m_Grid;
        Camera m_Camera;
        std::vector<Entity*> m_Entities;

        int RectId;
        std::list<Rectangle> m_Rectangles;
    };
}

#endif
