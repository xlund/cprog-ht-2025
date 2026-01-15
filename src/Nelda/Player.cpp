#include "Player.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/InputManager.h"
#include "Constants.h"
#include "WallDetection.h"

#include <cmath>

constexpr int TILE_SIZE = 100;

// Original sprite-storlek (PNG)
constexpr int PLAYER_SPRITE_WIDTH  = 36;
constexpr int PLAYER_SPRITE_HEIGHT = 63;

Player::Player(GameState& gs)
    : gameState_(gs), hp(100, 100) {}

Player* Player::create(GameState& gs) {
    return new Player(gs);
}

void Player::setup(GE::GameEngine* engine) {

    float scale = static_cast<float>(TILE_SIZE) / PLAYER_SPRITE_HEIGHT;

    spriteWidth  = static_cast<int>(std::round(PLAYER_SPRITE_WIDTH  * scale));
    spriteHeight = static_cast<int>(std::round(PLAYER_SPRITE_HEIGHT * scale));

    sprite = new GE::Sprite(
        x,
        y,
        spriteWidth,
        spriteHeight,
        constants::player_sprite
    );

  
    hitboxWidth  = static_cast<int>(spriteWidth  * 0.7f);
    hitboxHeight = static_cast<int>(spriteHeight * 0.4f);

    hitbox = new GE::Hitbox(
        x + (spriteWidth - hitboxWidth) / 2,
        y + (spriteHeight - hitboxHeight),
        hitboxWidth,
        hitboxHeight
    );

    hitbox->setTag("Player");

    engine->addComponent(hitbox);
    engine->addComponent(sprite);
}

void Player::update() {

    handleMovement();

    hitbox->setPosition(
        x + (spriteWidth - hitboxWidth) / 2,
        y + (spriteHeight - hitboxHeight)
    );

    sprite->setX(x + (TILE_SIZE - spriteWidth) / 2);
    sprite->setY(y + (TILE_SIZE - spriteHeight));

    wallDetection(*hitbox, "Wall", x, y);

    sprite->draw();
}

void Player::handleMovement() {

    if (GE::InputManager::isKeyDown("w"))
        y -= speed;
    if (GE::InputManager::isKeyDown("s"))
        y += speed;
    if (GE::InputManager::isKeyDown("a"))
        x -= speed;
    if (GE::InputManager::isKeyDown("d"))
        x += speed;
}
