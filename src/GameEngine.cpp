#include "GameEngine.h"
#include "../include/Constants.h"
#include <SDL3/SDL.h>

GE::GameEngine::GameEngine() {}

void GE::GameEngine::tick() {}

void GE::GameEngine::setFps(int fps) {
  this->fps = fps;
  this->tickInterval = constants::clockSpeed / this->fps;
}

void GE::GameEngine::start() {
  // Initialization
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  SDL_Window *win = SDL_CreateWindow("First", 500, 500, 0);
  SDL_Renderer *ren = SDL_CreateRenderer(win, NULL);

  // Loop
  SDL_Event event{};
  while (true) {
    Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
    // Process events
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_EVENT_MOUSE_MOTION:
        SDL_Log("We got a motion event!");
        SDL_Log("Current mouse position is: (%f, %f)", event.motion.x,
                event.motion.y);
      default:
        SDL_Log("Unhandled Event!");
        break;
      }
      long delay = nextTick - SDL_GetTicks();
      SDL_Log("Delay: %ld", delay);
      if (delay > 0)
        SDL_Delay(delay);
    }
    // Update objects
    // Render Changes
  }

  SDL_Delay(4000);
  // Shutdown
  SDL_DestroyWindow(win);
  SDL_Quit();
}
