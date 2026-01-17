#include "Player.h"
#include "../GameEngine/InputManager.h"
#include "Constants.h"
#include "WallDetection.h"

#include <cmath>

Player::Player(Game& g)
    : game_(g) {}

Player::~Player() {
  delete sprite;
  delete hitbox;
}

Player *Player::create(Game &g) { return new Player(g); }

void Player::setup(GE::GameEngine *engine) {

  float scale = static_cast<float>(constants::PLAYER_WORLD_HEIGHT) / constants::PLAYER_SPRITE_HEIGHT;

  spriteWidth = static_cast<int>(std::round(constants::PLAYER_SPRITE_WIDTH * scale));
  spriteHeight = static_cast<int>(std::round(constants::PLAYER_SPRITE_HEIGHT * scale));

  sprite = GE::Sprite::create(x, y, spriteWidth, spriteHeight,
                              constants::player_sprite, engine);

  hitbox = GE::Hitbox::create(x, y, spriteWidth, spriteHeight, engine);

  hitbox->setTag("player");
  hitbox->setOnEnter([this](GE::Hitbox *other) {
    if (other->getTag() == "goal") {
      game_.win();
    }
  });
}

void Player::update() {

  if (GE::InputManager::isKeyDown("w"))
    y -= speed;
  if (GE::InputManager::isKeyDown("s"))
    y += speed;
  if (GE::InputManager::isKeyDown("a"))
    x -= speed;
  if (GE::InputManager::isKeyDown("d"))
    x += speed;

  hitbox->setPosition(x, y);

  wallDetection(*hitbox, x, y);
}

void Player::render() {
  sprite->setX(x);
  sprite->setY(y);
  sprite->render();
}
