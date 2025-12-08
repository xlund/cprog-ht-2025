#include "GameEngine.h"
#include "../include/Constants.h"
#include "ScreenComponent.h"
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
  std::vector<Sprite *> sprites;

  while (true) {
    Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
    // Process events
    for (Sprite *sprite : sprites) {
      sprite->draw();
    }
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_EVENT_KEY_DOWN:
        if (event.key.key == SDLK_F) {
          SDL_Log("FPS: %uz", this->getFps());
        }
        if (event.key.key == SDLK_C) {
          SDL_Log("Creating screen component");
          Sprite *sprite =
              new GE::Sprite(renderer, constants::cool_link, 40, 40);
          sprites.push_back(sprite);
        }
        if (event.key.key == SDLK_D) {
        }
        if (event.key.key == SDLK_UP) {
          this->setFps(this->getFps() + 10);
        }
        if (event.key.key == SDLK_DOWN) {
          this->setFps(this->getFps() - 10);
        }
        if (event.key.key == SDLK_Q) {
          goto end_loop;
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
end_loop:

  // Shutdown
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
