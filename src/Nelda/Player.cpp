#include "Player.h"
#include "../GameEngine/InputManager.h"
#include "Constants.h"
#include "WallDetection.h"

#include <cmath>


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

    hitbox = new GE::Hitbox(x, y, spriteWidth, spriteHeight);
    hitbox->setTag("player");

    sprite = new GE::Sprite(
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

    if (GE::InputManager::isKeyDown("w")) y -= speed;
    if (GE::InputManager::isKeyDown("s")) y += speed;
    if (GE::InputManager::isKeyDown("a")) x -= speed;
    if (GE::InputManager::isKeyDown("d")) x += speed;

    wallDetection(*hitbox, "Wall", x, y);

    hitbox->setPosition(x, y);

    sprite->setX(x);
    sprite->setY(y);
    sprite->draw();
}
