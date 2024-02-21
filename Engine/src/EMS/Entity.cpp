#include "Engine/EMS/Entity.h"

namespace NUCTE_NS {
    Entity::Entity(const Vector2d& position, const Vector2d& size, const std::string& textureFilePath, bool hasPhysics, bool applyGravity)
        : position(position), size(size), hasPhysics(hasPhysics), textureFilePath(textureFilePath) {
        glGenVertexArrays(1, &vaoID);
        hasTexture = !textureFilePath.empty();
    }

    Entity::~Entity() {
        glDeleteVertexArrays(1, &vaoID);
    }

    void Entity::Update(float deltaTime) {
    }

    void Entity::Render() {
        // Rendering logic goes here
    }

    Vector2d Entity::GetPosition() const {
        return Vector2d{ 1,2 };
    }

    Vector2d Entity::GetSize() const {
        return Vector2d{ 1,2 };
    }

    bool Entity::HasTexture() const {
        return hasTexture;
    }

    const std::string& Entity::GetTextureFilePath() const {
        return textureFilePath;
    }
}

