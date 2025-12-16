#include "GameEngine.h"
#include "../include/Constants.h"
#include "Hitbox.h"
#include "InputManager.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <list>
#include <vector>

GE::GameEngine::GameEngine(int fps) : fps(fps) {
  window = SDL_CreateWindow("Nelda!", 500, 500, 0);
  renderer = SDL_CreateRenderer(window, NULL);
}
GE::GameEngine::GameEngine() {
  window = SDL_CreateWindow("Nelda!", 1080, 1080, 0);
  renderer = SDL_CreateRenderer(window, NULL);
}

void GE::GameEngine::tick() {}

void GE::GameEngine::setFps(int fps) {
  this->fps = fps;
  this->tickInterval = constants::clockSpeed / this->fps;
}

SDL_Renderer *GE::GameEngine::getRenderer() { return renderer; }

SDL_Window *GE::GameEngine::getWindow() { return window; }

int GE::GameEngine::getFps() { return fps; }

void GE::GameEngine::addScreenComponent(GE::Component *component) {
  components.push_back(component);
}

void GE::GameEngine::removeScreenComponent(GE::Component *component) {
  auto i = std::find(components.begin(), components.end(), component);
  components.erase(i);
}

void GE::GameEngine::start() {
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  // Loop
  SDL_Event event{};
  std::vector<GE::Component *> components;

  Hitbox *b1 = new Hitbox(10, 10, 100, 100);
  Hitbox *b2 = new Hitbox(10, 10, 100, 100);
  components.push_back(b1);
  components.push_back(b2);
  b1->setOnEnter([](Hitbox *other) { SDL_Log("i"); });
  b1->setOnExit([](Hitbox *other) { SDL_Log("Ut"); });

  while (true) {
    Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
    // Process events
    for (GE::Component *component : components) {
      component->update(renderer);
    }

    GE::InputManager::fetchKeys();
    if (GE::InputManager::isKeyPressed("c")) {
      SDL_Log("Creating screen component");
      Sprite *sprite =
          new GE::Sprite(0, 0, 0, 0, constants::cool_link, renderer);
      components.push_back(sprite);
      SDL_Log("Len: %ld", components.size());
    }

    long delay = nextTick - SDL_GetTicks();
    if (delay > 0)
      SDL_Delay(delay);

    // Update objects
    // Render Changes
    SDL_RenderPresent(renderer);
  }
  // Shutdown
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void GE::GameEngine::Hiting(Hitbox *other) { SDL_Log("i"); }

void GE::GameEngine::Exiting(Hitbox *other) { SDL_Log("ut"); }
