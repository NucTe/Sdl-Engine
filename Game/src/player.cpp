#include "player.h"


Player::Player(const Vector2& position, const Vector2& size) : wEntity(position, size, true, true) {}

Player::~Player() {}

void Player::Render() {
    Draw::Entity(this, { 255, 0, 0, 255 }, true);
}
