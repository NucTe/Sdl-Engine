#include "player.h"


Player::Player(const Vector2& position, const Vector2& size) : wEntity(position, size, true) {}

Player::~Player() {}

void Player::Render(SDL_Renderer* renderer) {
    Draw::Entity(renderer, this, { 255, 0, 0, 255 }, true);
}
