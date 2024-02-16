#include "SdlEngine/PhysicsObject.h"

PhysicsObject::PhysicsObject(const Vector2& position, const Vector2& size, bool applyGravity)
    : position(position), velocity(Vector2(0.0f, 0.0f)), acceleration(Vector2(0.0f, 0.0f)), collider({ size, Vector2(0.0f, 0.0f) }), applyGravity(applyGravity) {}


void PhysicsObject::Update(float deltaTime) {
 
}

Vector2 PhysicsObject::GetPosition() const {
    return position;
}

Vector2 PhysicsObject::GetSize() const {
    return collider.size;
}

void PhysicsObject::ApplyGravity(float gravity) {
    acceleration.y += gravity;
}

void PhysicsObject::SetGravityEnabled(bool enableGravity) {
    applyGravity = enableGravity;
}