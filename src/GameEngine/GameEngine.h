#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../include/Constants.h"
#include "GameObject.h"
#include <SDL3/SDL.h>
#include <functional>
#include <string>
#include <vector>

namespace GE {
class Component;
}

namespace GE {

enum class GameState { Running, Paused, Stopped };

class GameEngine {
public:
  GameEngine(int fps, std::string);
  GameEngine(std::string);
  void setup();
  void run();
  void shutdown();
  void reset();
  void setFps(const int fps);
  int getFps() const;
  void addComponent(GE::Component *);
  void removeComponent(GE::Component *);
  void addGameObject(GE::GameObject *);
  void removeGameObject(GE::GameObject *);
  static SDL_Renderer *getRenderer();
  static void setRenderer(SDL_Renderer *r);
  void setBackgroundColor(unsigned char, unsigned char, unsigned char,
                          unsigned char);
  void pause();
  void resume();
  void stop();
  void clearGameObjects();
  void clearComponents();
  void clearAll();
  static SDL_FRect createRect(float x, float y, float w, float h, Uint8 r,
                              Uint8 g, Uint8 b, Uint8 a = 255);
  GameState state() const;
  void setInputCallback(std::function<void()> cb);

private:
  GameState state_{GameState::Stopped};
  std::function<void()> inputCallback_;
  void handleGameKeys();
  void capFrameRate(Uint64 frame);
  void update();
  void render();
  Uint64 fps{60};
  Uint64 tickInterval{constants::clockSpeed / fps};
  static SDL_Renderer *renderer;
  SDL_Window *window;
  std::vector<GE::Component *> components;
  std::vector<GE::GameObject *> gameObjects;
  void gameObjectCleanUp();
  SDL_Color backgroundColor{0, 0, 0, 0};
};

} // namespace GE

#endif
