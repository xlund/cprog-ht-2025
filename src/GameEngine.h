#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "../include/Constants.h"
#include "Sprite.h"

namespace GE {
class GameEngine {
public:
  GameEngine();
  void start();
  void tick();
  void setFps(int fps);
  int getFps();
  int getTickInterval();
  bool spawnEntity(Sprite);

private:
  int fps{60};
  int tickInterval{constants::clockSpeed / fps};
};
} // namespace GE

#endif
