#ifndef PLAYER_H
#define PLAYER_H

#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/Sprite.h"
#include "Game.h"


class Player : public GE::GameObject {
public:
  static Player *create(Game&);

  ~Player();

  void setup(GE::GameEngine *engine) override;
  void update() override;
  void render() override;

private:
  Player(Game &);

  Game &game_;

  float speed{4.0f};

  GE::Sprite *sprite{nullptr};
  int spriteWidth{0};
  int spriteHeight{0};

  GE::Hitbox *hitbox{nullptr};
};

#endif
