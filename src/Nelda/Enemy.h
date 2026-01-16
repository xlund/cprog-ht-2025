#ifndef ENEMY_H
#define ENEMY_H
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/Sprite.h"
#include "Game.h"
#include "Health.h"

class Enemy : public GE::GameObject {
public:
  static Enemy *create(GE::GameObject*, int, GameState &);
  ~Enemy();
  void setup(GE::GameEngine *);
  void update();
  GE::Hitbox *getHitbox() const;
  Health getHealth();

private:
  Enemy(GE::GameObject*, int, GameState &);
  Health hp;
  int speed;
  float targetX;
  float targetY;
  GE::GameObject* target;
  GE::Hitbox *hitbox;
  GE::Sprite* sprite;
  // void wallDetection(GE::Hitbox*);
  GameState &gameState_;
};

#endif
