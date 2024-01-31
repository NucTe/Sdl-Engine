#pragma once

#include "../Vector2.h"

class SDL_Renderer;

class wEntity {
public:
    wEntity(const Vector2& position, const Vector2& size);
    virtual ~wEntity();

    virtual void Render(SDL_Renderer* renderer) = 0;

    Vector2 GetPosition() const;
    Vector2 GetSize() const;

private:
    Vector2 position;
    Vector2 size;
};
