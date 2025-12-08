#include "GameEngine.h"
#include "../include/Constants.h"
#include <SDL3/SDL.h>

GE::GameEngine::GameEngine() {}

void GE::GameEngine::tick() {}

void GE::GameEngine::setFps(int fps) {
  this->fps = fps;
  this->tickInterval = constants::clockSpeed / this->fps;
}

int GE::GameEngine::getFps() { return fps; }

void GE::GameEngine::start() {
  // Initialization
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  SDL_Window *win = SDL_CreateWindow("Nelda!", 500, 500, 0);
  SDL_Renderer *ren = SDL_CreateRenderer(win, "NELDA!");

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
    SDL_RenderPresent(ren);
  }

  SDL_Delay(4000);
  // Shutdown
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(ren);
  SDL_Quit();
}
