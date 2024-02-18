#include "Engine/EMS/Entity.h"

namespace NUCTE_NS {
    Entity::Entity(const Vector2& position, const Vector2& size, const std::string& textureFilePath, bool hasPhysics, bool applyGravity)
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

    Vector2 Entity::GetPosition() const {
        return Vector2{ 1,2 };
    }

    Vector2 Entity::GetSize() const {
        return Vector2{ 1,2 };
    }

    bool Entity::HasTexture() const {
        return hasTexture;
    }

    const std::string& Entity::GetTextureFilePath() const {
        return textureFilePath;
    }
}

