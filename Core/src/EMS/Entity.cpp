#include "SdlEngine/EMS/wEntity.h"
#include <iostream>

wEntity::wEntity(const Vector2& position, const Vector2& size, bool hasPhysics, bool applyGravity, bool hasTexture)
    : position(position), size(size), physicsObject(position, size, applyGravity), hasPhysics(hasPhysics), hasTexture(hasTexture) {
    glGenVertexArrays(1, &vaoID); // Generate VAO for OpenGL rendering
}

wEntity::~wEntity() {
    glDeleteVertexArrays(1, &vaoID); // Delete VAO when entity is destroyed
}

void wEntity::Update(float deltaTime) {
    if (hasPhysics) {
        physicsObject.Update(deltaTime);
    }
}

void wEntity::Render() {
    std::cout << "Rendering wEntity using OpenGL" << std::endl;
}

Vector2 wEntity::GetPosition() const {
    return physicsObject.GetPosition();
}

Vector2 wEntity::GetSize() const {
    return physicsObject.GetSize();
}

PhysicsObject* wEntity::GetPhysicsObject() const {
    return const_cast<PhysicsObject*>(&physicsObject);
}

bool wEntity::HasTexture() const {
    return hasTexture;
}
