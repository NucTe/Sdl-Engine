#include "SdlEngine/EMS/wEntity.h"

wEntity::wEntity(const Vector2& position, const Vector2& size, bool hasPhysics)
    : position(position), size(size), physicsObject(position, size), hasPhysics(hasPhysics) {}

wEntity::~wEntity() {
}

void wEntity::Update(float deltaTime) {
    if (hasPhysics) {
        physicsObject.Update(deltaTime);
    }
}

void wEntity::Render(SDL_Renderer* renderer) {
}

Vector2 wEntity::GetPosition() const {
    return physicsObject.GetPosition();
}

Vector2 wEntity::GetSize() const {
    return physicsObject.GetSize();
}
