#ifndef WALL_H
#define WALL_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/Sprite.h"
#include <vector>
class Wall : public GE::GameObject {
public:
  ~Wall();
  static Wall *create(float, float, float);
  void setup(GE::GameEngine *);
  void update();
  void render();

private:
  Wall(float, float, float);
  std::vector<GE::Hitbox *> hitboxes;
  float length;
  GE::Sprite *sprite;
};

#endif
