#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glew.h>
#include "SdlEngine/Vector2.h"
#include "Engine/utils.h"
#include <string>

namespace NUCTE_NS {
    class Entity {
    public:
        Entity(const Vector2& position, const Vector2& size, const std::string& textureFilePath, bool hasPhysics, bool applyGravity = true);
        ~Entity();

        void Update(float deltaTime);
        void Render();

        bool HasTexture() const;

        Vector2 GetPosition() const;
        Vector2 GetSize() const;

       // PhysicsObject* GetPhysicsObject() const;

        const std::string& GetTextureFilePath() const;

    private:
        Vector2 position;
        Vector2 size;
       // PhysicsObject physicsObject;

        bool hasPhysics;
        GLuint vaoID;
        bool hasTexture;

        std::string textureFilePath;
    };
}

#endif