#ifndef PLAYER_H
#define PLAYER_H

#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/Sprite.h"
#include "Game.h"
#include "Health.h"
#include "PlayerMovement.h"

namespace GE {

/*
  Player ett GameObject.
  Den samlar ihop logik (Movement),
  rendering (Sprite) och kollision (Hitbox).
*/
class Player : public GameObject {
public:
  static Player *create(GameState &);

  void setup(GameEngine *) override;

  void update() override;

private:
  Player(GameState &);
  GameState &gameState_;
  // Positionenrna
  Health hp;

  // Rörelselogik - osäker här?
  Movement movement;

  // komponenter kopplade till spelare
  Sprite *sprite{nullptr};
  Hitbox *hitbox{nullptr};
};

} // namespace GE

#endif
