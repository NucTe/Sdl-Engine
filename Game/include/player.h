#pragma once

#include "SdlEngine/EMS/wEntity.h"
#include "SdlEngine/draw.h"

class Player : public wEntity {
public:
    Player(const Vector2& position, const Vector2& size);
    ~Player() override;
    void Render(SDL_Renderer* renderer) override;
};
