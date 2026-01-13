#ifndef PLAYER_H
#define PLAYER_H

#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/Sprite.h"
#include "Game.h"
#include "Health.h"

namespace GE {

class GameEngine;

class Player : public GameObject {
public:
  static Player *create(GameState &);

  void setup(GameEngine *engine) override;
  void update() override;
  void handleMovement();

private:
  Player(GameState &);
  GameState &gameState_;
  // Positionenrna
  Health hp;

  float speed{3.0f};

  Sprite *sprite{nullptr};
  Hitbox *hitbox{nullptr};

  int spriteWidth{0};
  int spriteHeight{0};
};

} // namespace GE

#endif // PLAYER_H
