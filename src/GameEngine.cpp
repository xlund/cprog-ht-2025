#include "GameEngine.h"
#include "../include/Constants.h"
#include "ScreenComponent.h"
#include "Sprite.h"
#include "Text.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <algorithm>
#include <vector>
#include <iostream>

namespace GE {

GameEngine::GameEngine(int fps) : fps(fps) {
  window = SDL_CreateWindow("Nelda!", 500, 500, 0);
  renderer = SDL_CreateRenderer(window, nullptr);
}

GameEngine::GameEngine() {
  window = SDL_CreateWindow("Nelda!", 1080, 1080, 0);
  renderer = SDL_CreateRenderer(window, nullptr);
}

GameEngine::~GameEngine() {
  delete bgSound; // Städa ljudet
}

void GameEngine::tick() {}

void GameEngine::setFps(int fps) {
  this->fps = fps;
  this->tickInterval = constants::clockSpeed / this->fps;
}

SDL_Renderer *GameEngine::getRenderer() { return renderer; }
SDL_Window *GameEngine::getWindow() { return window; }
int GameEngine::getFps() { return fps; }

void GameEngine::addScreenComponent(ScreenComponent *component) {
  screenComponents.push_back(component);
}

void GameEngine::removeScreenComponent(ScreenComponent *component) {
  auto it =
      std::find(screenComponents.begin(), screenComponents.end(), component);
  if (it != screenComponents.end())
    screenComponents.erase(it);
}

void GE::GameEngine::start() {
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  TTF_Init();
  // Loop
  SDL_Event event{};
  std::vector<ScreenComponent *> components;
  Text *text = new GE::Text("Linus", 50, 50);
  components.push_back(text);
  text->setColor(255, 255, 255, 255);
  text->draw();
  int x = 0;
  while (true) {
    SDL_RenderClear(renderer);
    Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
    // Process events
    for (ScreenComponent *component : components) {
      component->update(renderer);
    }
    // ppdatera ljudet så det loopar
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
          components.push_back(sprite);
        }
        if (event.key.key == SDLK_L) {
          text->setRotation(++x);
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

        long delay = nextTick - SDL_GetTicks();
        if (delay > 0)
          SDL_Delay(delay);

      }
    }
    SDL_RenderPresent(renderer);
  }
end_loop:
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

} // namespace GE
