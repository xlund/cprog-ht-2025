#ifndef ENEMY_H
#define ENEMY_H
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"
#include "Game.h"
#include "Health.h"
#include "TempObject.h"

class Enemy : public GE::GameObject {
public:
  static Enemy *create(TempObject, int, int, int, GameState &);
  void setup(GE::GameEngine *);
  void update();
  GE::Hitbox *getHitbox() const;
  Health getHealth();

private:
  Enemy(TempObject, int, int, int, GameState &);
  Health hp;
  int speed;
  int targetX;
  int targetY;
  TempObject target;
  GE::Hitbox *hitbox;
  // void wallDetection(GE::Hitbox*);
  GameState &gameState_;
};

#endif
