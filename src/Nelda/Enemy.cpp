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

Enemy::Enemy(GE::GameObject* target, int speed, GameState &gs,GE::GameEngine* ge):GameObject(ge), speed(speed), target(target), gameState_(gs) {
      //std::cout<<"Enemy::Enemy()\n";
}


Enemy *Enemy::create(GE::GameObject* target, int speed, GameState &gs,GE::GameEngine* ge) {
  return new Enemy(target, speed, gs,ge);
}

Enemy::~Enemy(){
  //std::cout<<"Enemy::~Enemy()\n";
  delete sprite;
  delete hitbox;
  gameEngine->removeGameObject(this);
}

Health Enemy::getHealth() { return hp; }

GE::Hitbox *Enemy::getHitbox() const { return hitbox; }
void Enemy::setup(GE::GameEngine *engine) {
  hitbox = GE::Hitbox::create(x,y,32,54,engine);
  sprite = GE::Sprite::create(x,y,0,0,constants::enemy_image,engine);
  hitbox->setOnEnter([this](GE::Hitbox *other) {
    // wallDetection(other);
    if (other->getTag() == "player") {
      this->hp.current -= 50;
      if (this->hp.isDead()) {
        gameState_.score->add(100);
      }
    }
  });
  speed = 1;
}

void Enemy::update() {

  /*target.getPos(targetX,targetY);
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
  }*/

  if (GE::InputManager::isKeyDown("w")) {
    y -= speed;
  }
  if (GE::InputManager::isKeyDown("s")) {
    y += speed;
  }
  if (GE::InputManager::isKeyDown("a")) {
    x -= speed;
  }
  if (GE::InputManager::isKeyDown("d")) {
    x += speed;
  }

  hitbox->setPosition(x, y);
  wallDetection(*hitbox, "Wall", x, y);
  sprite->setX(x);
  sprite->setY(y);
  sprite->draw();
}
