#pragma once

#include "../Vector2.h"
#include "../PhysicsObject.h"
#include "SDL2/SDL.h"

class wEntity {
public:
    wEntity(const Vector2& position, const Vector2& size, bool hasPhysics);
    virtual ~wEntity();

    virtual void Update(float deltaTime);
    virtual void Render(SDL_Renderer* renderer);

    Vector2 GetPosition() const;
    Vector2 GetSize() const;

    PhysicsObject& GetPhysicsObject();

private:
    Vector2 position;
    Vector2 size;
    PhysicsObject physicsObject;

    bool hasPhysics;
};
