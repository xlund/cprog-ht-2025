#include "Player.h"
#include "../GameEngine/InputManager.h"
#include "Constants.h"
#include "WallDetection.h"

#include <cmath>

// Original PNG-storlek
constexpr int PLAYER_SPRITE_WIDTH  = 36;
constexpr int PLAYER_SPRITE_HEIGHT = 63;

// Hur hög spelaren ska vara i världen (matchar tiles)
constexpr int PLAYER_WORLD_HEIGHT = 64;

Player::Player(GameState& gs)
    : GE::GameObject(0, 0), gameState_(gs), hp(100, 100) {}

Player* Player::create(GameState& gs) {
    return new Player(gs);
}

void Player::setup(GE::GameEngine* engine) {

    /* =========================
       SPRITE SCALE
       ========================= */
    float scale = static_cast<float>(PLAYER_WORLD_HEIGHT)
                / PLAYER_SPRITE_HEIGHT;

    spriteWidth  = static_cast<int>(std::round(PLAYER_SPRITE_WIDTH  * scale));
    spriteHeight = static_cast<int>(std::round(PLAYER_SPRITE_HEIGHT * scale));

    sprite = new GE::Sprite(
        x,
        y,
        spriteWidth,
        spriteHeight,
        constants::player_sprite
    );

    /* =========================
       TIGHT FEET HITBOX
       ========================= */
    hitboxWidth  = static_cast<int>(spriteWidth  * 0.6f);
    hitboxHeight = static_cast<int>(spriteHeight * 0.35f);

    hitbox = new GE::Hitbox(
        hitboxX(),
        hitboxY(),
        hitboxWidth,
        hitboxHeight
    );

    hitbox->setTag("player");

    engine->addComponent(hitbox);
    engine->addComponent(sprite);
}

void Player::update() {

    float hbX = 0.0f;
    float hbY = 0.0f;

    /* =========================
       X-AXIS
       ========================= */
    handleMovementX();

    hbX = hitboxX();
    hbY = hitboxY();
    hitbox->setPosition(hbX, hbY);

    wallDetection(*hitbox, "Wall", hbX, hbY);

    // Översätt tillbaka till sprite-position
    x = hbX - (spriteWidth - hitboxWidth) / 2;

    /* =========================
       Y-AXIS
       ========================= */
    handleMovementY();

    hbX = hitboxX();
    hbY = hitboxY();
    hitbox->setPosition(hbX, hbY);

    wallDetection(*hitbox, "Wall", hbX, hbY);

    // Översätt tillbaka till sprite-position
    y = hbY - (spriteHeight - hitboxHeight);

    // 🔒 Extra skydd: sprite får inte gå in i väggen
    if (y < hbY - (spriteHeight - hitboxHeight)) {
        y = hbY - (spriteHeight - hitboxHeight);
    }

    /* =========================
       SPRITE
       ========================= */
    sprite->setX(x);
    sprite->setY(y);
    sprite->draw();
}

void Player::handleMovementX() {
    if (GE::InputManager::isKeyDown("a")) {
        x -= speed;
    }
    if (GE::InputManager::isKeyDown("d")) {
        x += speed;
    }
}

void Player::handleMovementY() {
    if (GE::InputManager::isKeyDown("w")) {
        y -= speed;
    }
    if (GE::InputManager::isKeyDown("s")) {
        y += speed;
    }
}

/* =========================
   HITBOX HELPERS
   ========================= */

int Player::hitboxX() const {
    return static_cast<int>(
        x + (spriteWidth - hitboxWidth) / 2
    );
}

int Player::hitboxY() const {
    return static_cast<int>(
        y + (spriteHeight - hitboxHeight)
    );
}
