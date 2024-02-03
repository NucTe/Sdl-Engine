#pragma once

#include "../Vector2.h"
#include "../PhysicsObject.h"
#include <GL/glew.h>

class wEntity {
public:
    wEntity(const Vector2& position, const Vector2& size, bool hasPhysics, bool applyGravity = true, bool hasTexture = false);
    virtual ~wEntity();

    virtual void Update(float deltaTime);
    virtual void Render();

    bool HasTexture() const;

    Vector2 GetPosition() const;
    Vector2 GetSize() const;

    PhysicsObject* GetPhysicsObject() const;

private:
    Vector2 position;
    Vector2 size;
    PhysicsObject physicsObject;

    bool hasPhysics;
    GLuint vaoID;
    bool hasTexture;
};
