#include "Engine/EMS/Entity.h"

Entity::Entity(const Vector2& position, const Vector2& size, const std::string& textureFilePath, bool hasPhysics, bool applyGravity)
    : position(position), size(size), physicsObject(position, size, applyGravity), hasPhysics(hasPhysics), textureFilePath(textureFilePath) {
    glGenVertexArrays(1, &vaoID);
    hasTexture = !textureFilePath.empty();
}

Entity::~Entity() {
    glDeleteVertexArrays(1, &vaoID);
}

void Entity::Update(float deltaTime) {
    if (hasPhysics) {
        physicsObject.Update(deltaTime);
    }
}

void Entity::Render() {
    // Rendering logic goes here
}

Vector2 Entity::GetPosition() const {
    return physicsObject.GetPosition();
}

Vector2 Entity::GetSize() const {
    return physicsObject.GetSize();
}

PhysicsObject* Entity::GetPhysicsObject() const {
    return const_cast<PhysicsObject*>(&physicsObject);
}

bool Entity::HasTexture() const {
    return hasTexture;
}

const std::string& Entity::GetTextureFilePath() const {
    return textureFilePath;
}
