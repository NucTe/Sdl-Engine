#include "SdlEngine/EMS/Entity.h"

wEntity::wEntity(const Vector2& position, const Vector2& size)
    : position(position), size(size) {}

wEntity::~wEntity() {}

Vector2 wEntity::GetPosition() const {
    return position;
}

Vector2 wEntity::GetSize() const {
    return size;
}
