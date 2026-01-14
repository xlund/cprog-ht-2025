#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../include/Constants.h"
#include "Component.h"
#include "GameObject.h"
#include <SDL3/SDL.h>
#include <string>
#include <vector>

namespace GE {

class GameEngine {
public:
  GameEngine(int fps, std::string);
  GameEngine(std::string);
  void start();
  bool tick();
  void setFps(const int fps);
  int getFps() const;
  void addComponent(GE::Component *);
  void removeComponent(GE::Component *);
  void clearComponent();
  void addGameObject(GE::GameObject *);
  void clearGameobjects();
  void removeGameObject(GE::GameObject *);
  static SDL_Renderer *getRenderer();
  static void setRenderer(SDL_Renderer *r);

private:
  int fps{60};
  int tickInterval{constants::clockSpeed / fps};
  static SDL_Renderer *renderer;
  SDL_Window *window;
  std::vector<GE::Component *> components;
  std::vector<GE::GameObject *> gameObjects;
};

} // namespace GE

#endif
