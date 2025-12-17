#include "AnimatedSprite.h"
#include "Constants.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3_image/SDL_image.h>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <thread>



int main(int argc, char *argv[]) {
  
  GE::GameEngine game("Nelda");
  game.start();
  int interval{constants::clockSpeed / FPS};
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  bool running = true;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Animation test", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, NULL);

  GE::AnimatedSprite *sprite = new GE::AnimatedSprite(
      9, 1, 48, 48, 50, 50, 0, 0, constants::sample_sprite_sheet, renderer);
  sprite->setCurrentAnimation(
      {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}});
  GE::AnimatedSprite *sprite2 = new GE::AnimatedSprite(
      2, 1, 32, 32, 150, 150, 0, 0, constants::sample_sprite_2, renderer);
  sprite2->setCurrentAnimation({{0, 0}, {0, 1}});

  SDL_Event e;
  while (running) {
    SDL_RenderClear(renderer);
    Uint64 frameStart = SDL_GetTicks();
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }
    sprite->update(renderer);
    sprite2->update(renderer);
    SDL_RenderPresent(renderer);
    Uint64 frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < interval) {
      SDL_Delay(interval - frameTime);
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  return 0;
}
