#include "Enemy.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/InputManager.h"
#include "../GameEngine/Sprite.h"
#include "Game.h"
#include "Goal.h"
#include "Health.h"
#include "WallDetection.h"
#include <iostream>

Enemy::Enemy(GE::GameObject* target, int speed, Game &g) : speed(speed), target(target), game_(g) {
      //std::cout<<"Enemy::Enemy()\n";
}


Enemy *Enemy::create(GE::GameObject* target, int speed, Game &g) {
  return new Enemy(target, speed, g);
}

Enemy::~Enemy() {
  // std::cout<<"Enemy::~Enemy()\n";
  delete sprite;
  delete hitbox;
}

Health Enemy::getHealth() { return hp; }

GE::Hitbox *Enemy::getHitbox() const { return hitbox; }
void Enemy::setup(GE::GameEngine *engine) {
  hitbox = GE::Hitbox::create(x, y, 32, 54, engine);
  sprite = GE::Sprite::create(x, y, 0, 0, constants::enemy_image, engine);
  hitbox->setOnEnter([this](GE::Hitbox *other) {
    if (other->getTag() == "player") {
      game_.lose();
    }
  });
  speed = 3;
}

void Enemy::update() {

  target->getPos(targetX,targetY);
  if(targetX<x){
      x-=speed;
  }
  if(targetX>x){
      x+=speed;
  }
  if(targetY<y){
      y-=speed;
  }
  if(targetY>y){
      y+=speed;
  }

  hitbox->setPosition(x, y);
  wallDetection(*hitbox, "Wall", x, y);
}

void Enemy::render() {
  sprite->setX(x);
  sprite->setY(y);
  sprite->render();
}
