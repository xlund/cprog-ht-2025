#include "Player.h"
#include "../GameEngine/InputManager.h"
#include "Constants.h"
#include "WallDetection.h"

#include <cmath>

// Original PNG-storlek
constexpr int PLAYER_SPRITE_WIDTH  = 36;
constexpr int PLAYER_SPRITE_HEIGHT = 63;


constexpr int PLAYER_WORLD_HEIGHT = 64;

Player::Player(GameState& gs)
    : GE::GameObject(0, 0), gameState_(gs), hp(100, 100) {}

Player* Player::create(GameState& gs) {
    return new Player(gs);
}

void Player::setup(GE::GameEngine* engine) {


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

    handleMovementX();

    hbX = hitboxX();
    hbY = hitboxY();
    hitbox->setPosition(hbX, hbY);

    wallDetection(*hitbox, "Wall", hbX, hbY);


    x = hbX - (spriteWidth - hitboxWidth) / 2;


    handleMovementY();

    hbX = hitboxX();
    hbY = hitboxY();
    hitbox->setPosition(hbX, hbY);

    wallDetection(*hitbox, "Wall", hbX, hbY);

    y = hbY - (spriteHeight - hitboxHeight);


    if (y < hbY - (spriteHeight - hitboxHeight)) {
        y = hbY - (spriteHeight - hitboxHeight);
    }


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
