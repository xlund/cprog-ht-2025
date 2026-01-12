#include "../include/Constants.h"
#include "Constants.h"
#include "GameEngine/AnimatedSprite.h"
#include "GameEngine/GameEngine.h"
#include "Nelda/Enemy.h"
#include "Nelda/LevelCreator.h"
#include "Nelda/TempObject.h"
#include "Nelda/Wall.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3_image/SDL_image.h>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <thread>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080
#define FPS 60

int main(int argc, char *argv[]) {
  GE::GameEngine game = GE::GameEngine("Nelda");

  LevelCreator lc = LevelCreator("./src/Nelda/level.txt", 64);
  lc.setGameObject('w', []() { return Wall::create(200, 200, 64); });
  lc.setGameObject(
      'e', []() { return Enemy::create(TempObject(400, 500), 10, 10, 1); });
  lc.make(game);

  game.start();
  GE::AnimatedSprite *sprite = new GE::AnimatedSprite(
      9, 1, 48, 48, 50, 50, 0, 0, constants::sample_sprite_sheet);
  sprite->setCurrentAnimation(
      {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}});
  GE::AnimatedSprite *sprite2 = new GE::AnimatedSprite(
      2, 1, 32, 32, 150, 150, 0, 0, constants::sample_sprite_2);
  sprite2->setCurrentAnimation({{0, 0}, {0, 1}});

  return 0;
}
