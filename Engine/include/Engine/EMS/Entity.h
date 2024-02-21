#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glew.h>
#include "Physics/2d/Vector2d.h"
#include "Engine/utils.h"
#include <string>

namespace NUCTE_NS {
    class Entity {
    public:
        Entity(const Vector2d& position, const Vector2d& size, const std::string& textureFilePath, bool hasPhysics, bool applyGravity = true);
        ~Entity();

        void Update(float deltaTime);
        void Render();

        bool HasTexture() const;

        Vector2d GetPosition() const;
        Vector2d GetSize() const;

       // PhysicsObject* GetPhysicsObject() const;

        const std::string& GetTextureFilePath() const;

    private:
        Vector2d position;
        Vector2d size;
       // PhysicsObject physicsObject;

        bool hasPhysics;
        GLuint vaoID;
        bool hasTexture;

        std::string textureFilePath;
    };
}

#endif