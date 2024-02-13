#pragma once

#include "Vector2.h"
#include "Collider.h"

class PhysicsObject {
public:
    PhysicsObject(const Vector2& position, const Vector2& size, bool applyGravity = true);

    void Update(float deltaTime);

    Vector2 GetPosition() const;
    Vector2 GetSize() const;

    void ApplyGravity(float gravity);

    void SetGravityEnabled(bool enableGravity);
private:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;

    Collider collider;

    bool applyGravity;
};
