#include "GameEngine.h"
#include "../include/Constants.h"
#include "ScreenComponent.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <list>
#include <vector>

GE::GameEngine::GameEngine(int fps) : fps(fps) {
  window = SDL_CreateWindow("Nelda!", 500, 500, 0);
  renderer = SDL_CreateRenderer(window, "NELDA!");
}
GE::GameEngine::GameEngine() {
  window = SDL_CreateWindow("Nelda!", 500, 500, 0);
  renderer = SDL_CreateRenderer(window, "NELDA!");
}

void GE::GameEngine::tick() {}

void GE::GameEngine::setFps(int fps) {
  this->fps = fps;
  this->tickInterval = constants::clockSpeed / this->fps;
}

SDL_Renderer *GE::GameEngine::getRenderer() { return renderer; }

SDL_Window *GE::GameEngine::getWindow() { return window; }

int GE::GameEngine::getFps() { return fps; }

void GE::GameEngine::addScreenComponent(GE::ScreenComponent *component) {
  screenComponents.push_back(component);
}

void GE::GameEngine::removeScreenComponent(ScreenComponent *component) {
  auto i =
      std::find(screenComponents.begin(), screenComponents.end(), component);
  screenComponents.erase(i);
}

void GE::GameEngine::start() {
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  // Loop
  SDL_Event event{};
  while (true) {
    Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
    // Process events
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_EVENT_KEY_DOWN:
        if (event.key.key == SDLK_F) {
          SDL_Log("FPS: %d", this->getFps());
        }
        if (event.key.key == SDLK_C) {

          SDL_Log("Creating scren component");
          SDL_Log("Current components: %zu", screenComponents.size());
          ScreenComponent *comp = new ScreenComponent();
          addScreenComponent(comp);
          SDL_Log("Current components (after addition): %zu",
                  screenComponents.size());
        }
        if (event.key.key == SDLK_D) {

          SDL_Log("Deleting screen component");
          ScreenComponent *comp = new ScreenComponent();
          addScreenComponent(comp);
          removeScreenComponent(comp);
          SDL_Log("Current components (after addition): %zu",
                  screenComponents.size());
        }
        if (event.key.key == SDLK_UP) {
          this->setFps(this->getFps() + 10);
        }
        if (event.key.key == SDLK_DOWN) {
          this->setFps(this->getFps() - 10);
        }
      default:
        break;
      }
      long delay = nextTick - SDL_GetTicks();
      if (delay > 0)
        SDL_Delay(delay);
    }
    // Update objects
    // Render Changes
    SDL_RenderPresent(renderer);
  }

  // Shutdown
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
