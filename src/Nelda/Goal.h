#ifndef GOAL_H
#define GOAL_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"

namespace GE {

class Goal : public GameObject {
public:
  static Goal *create();

  void setup(GE::GameEngine *) override;
  void update() override;

  bool isCollected() const;

private:
  Goal();
  bool collected{false};
  Hitbox *hitbox{nullptr};
};

} // namespace GE

#endif
