#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../include/Constants.h"
#include "Component.h"
#include <SDL3/SDL.h>
#include <vector>
#include "GameObject.h"
#include <string>

namespace GE {

class GameEngine {
public:
  GameEngine(int fps,std::string);
  GameEngine(std::string);
  void start();
  bool tick();
  void setFps(const int fps);
  int getFps() const;
  void addComponent(GE::Component *);
  void removeComponent(GE::Component *);
  void addGameObject(GE::GameObject *);
  void removeGameObject(GE::GameObject *);
  SDL_Renderer* getRenderer();
private:
  int fps{60};
  int tickInterval{constants::clockSpeed / fps};
  SDL_Renderer *renderer;
  SDL_Window *window;
  std::vector<GE::Component *> components;
  std::vector<GE::GameObject *> gameObjects;

};

} // namespace GE

#endif
