#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <list>
#include <glm/glm.hpp>
#include <vector>

#include "Engine/EMS/EntityManager.h"
#include "Engine/GameLogic/Grid.h"
#include "Engine/GameLogic/Camera.h"
#include "Physics/2d/Physics.h"

namespace NUCTE_NS {

    class Renderer;

    struct Rectangle {
        int id;
        glm::vec2 position;
        glm::vec2 size;
        glm::vec4 color;
        PhysicsObject* physicsObject;
    };

    class GameWorld {
    public:
        GameWorld(EntityManager& entityManager, Renderer& renderer);
        ~GameWorld();

        void Update(float dt);

        void AddRectangle(const glm::vec2& position, glm::vec2& size, const glm::vec4& color, PhysicsObject& physicsObject);
        void RmRectangle(int id);

        const std::list<Rectangle>& GetRectangles() const;
        Grid& GetGrid();
        Camera& GetCamera();

        const std::vector<Entity*>& GetEntities() const;

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
