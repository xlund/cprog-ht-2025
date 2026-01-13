#include "Player.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/InputManager.h"
#include "WallDetection.h"
#include "Constants.h"

#include <cmath>

namespace GE {

constexpr int TILE_SIZE = 100;

Player* Player::create() {
    return new Player();
}

Player::Player() = default;

void Player::setup(GameEngine* engine) {

    hitbox = new Hitbox(x, y, TILE_SIZE, TILE_SIZE);
    hitbox->setTag("Player");

    constexpr int PLAYER_SPRITE_WIDTH  = 32; //!Skalningen funkar ej
    constexpr int PLAYER_SPRITE_HEIGHT = 54;

    float scale =
        static_cast<float>(TILE_SIZE) / PLAYER_SPRITE_HEIGHT;

    spriteWidth  =
        static_cast<int>(std::round(PLAYER_SPRITE_WIDTH  * scale));
    spriteHeight =
        static_cast<int>(std::round(PLAYER_SPRITE_HEIGHT * scale));

    sprite = new Sprite(
        x,
        y,
        spriteWidth,
        spriteHeight,
        constants::player_sprite
    );

    engine->addComponent(hitbox);
    engine->addComponent(sprite);
}

void Player::update() {

    handleMovement();
    wallDetection(*hitbox, "Wall", x, y);

    hitbox->setPosition(x, y);

    sprite->setX(x + (TILE_SIZE - spriteWidth) / 2);
    sprite->setY(y + (TILE_SIZE - spriteHeight));

    sprite->draw();
}

void Player::handleMovement() {

    if (InputManager::isKeyDown("w")) y -= speed;
    if (InputManager::isKeyDown("s")) y += speed;
    if (InputManager::isKeyDown("a")) x -= speed;
    if (InputManager::isKeyDown("d")) x += speed;
}

} // namespace GE
