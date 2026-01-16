#include "Player.h"
#include "../GameEngine/InputManager.h"
#include "Constants.h"
#include "WallDetection.h"

#include <cmath>

constexpr int PLAYER_SPRITE_WIDTH  = 36;
constexpr int PLAYER_SPRITE_HEIGHT = 63;
constexpr int PLAYER_WORLD_HEIGHT = 64;

Player::Player(GameState& gs,GE::GameEngine* ge)
    : GE::GameObject(ge), gameState_(gs), hp(100, 100) {}

Player::~Player() {
    delete sprite;
    delete hitbox;
}

Player* Player::create(GameState& gs, GE::GameEngine* ge) {
    return new Player(gs,ge);
}

void Player::setup(GE::GameEngine* engine) {

    float scale = static_cast<float>(PLAYER_WORLD_HEIGHT)
                / PLAYER_SPRITE_HEIGHT;

    spriteWidth  = static_cast<int>(std::round(PLAYER_SPRITE_WIDTH  * scale));
    spriteHeight = static_cast<int>(std::round(PLAYER_SPRITE_HEIGHT * scale));

    sprite = GE::Sprite::create(
        x,
        y,
        spriteWidth,
        spriteHeight,
        constants::player_sprite,
        engine
    );


    hitbox = GE::Hitbox::create(x,y,spriteWidth,spriteHeight, engine);

    hitbox->setTag("player");
}

void Player::update() {

    if (GE::InputManager::isKeyDown("w")) y -= speed;
    if (GE::InputManager::isKeyDown("s")) y += speed;
    if (GE::InputManager::isKeyDown("a")) x -= speed;
    if (GE::InputManager::isKeyDown("d")) x += speed;


    hitbox->setPosition(x, y);

    wallDetection(*hitbox, "Wall", x, y);

    sprite->setX(x);
    sprite->setY(y);
    sprite->draw();
}
