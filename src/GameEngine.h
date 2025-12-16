#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../include/Constants.h"
#include "Hitbox.h"
#include "SoundPlayer.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <vector>

namespace GE {

class GameEngine {
public:
  GameEngine(int fps);
  GameEngine();
  void start();
  void tick();
  void setFps(int fps);
  int getFps();
  int getTickInterval();
  bool spawnEntity(Sprite);
  SDL_Renderer *getRenderer();
  SDL_Window *getWindow();
  std::vector<Component *> getScreenComponents();
  void addScreenComponent(GE::Component *);
  void removeScreenComponent(GE::Component *);
  void removeAllScreenComponents();

  void Hiting(Hitbox *);
  void Exiting(Hitbox *);

private:
  int fps{60};
  int tickInterval{constants::clockSpeed / fps};
  SDL_Renderer *renderer;
  SDL_Window *window;
  std::vector<GE::Component *> components;
};

} // namespace GE

#endif
