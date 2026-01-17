#ifndef GOAL_H
#define GOAL_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/Rectangle.h"

class Game; // forward declaration

class Goal : public GE::GameObject {
public:
  static Goal *create(Game *game);

  ~Goal() {}
  void setup(GE::GameEngine *engine) override;

  void update() override;


private:
  Goal(Game *game);

  Game *game;
  GE::Hitbox *hitbox{nullptr};
  GE::Rectangle *rect_;
};

#endif
