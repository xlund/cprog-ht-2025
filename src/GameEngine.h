#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "../include/Constants.h"
#include "Sprite.h"
#include <SDL3/SDL.h>

namespace GE {
class GameEngine {
public:
  GameEngine(int fps);
  void start();
  void tick();
  void setFps(int fps);
  int getFps();
  int getTickInterval();
  bool spawnEntity(Sprite);
  SDL_Renderer *getRenderer();
  SDL_Window *getWindow();

private:
  int fps{60};
  int tickInterval{constants::clockSpeed / fps};
  SDL_Renderer *renderer;
  SDL_Window *window;
};
} // namespace GE

#endif
