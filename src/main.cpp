#include "../include/Constants.h"
#include "Constants.h"
#include "GameEngine/AnimatedSprite.h"
#include "GameEngine/GameEngine.h"
#include "Nelda/Enemy.h"
#include "Nelda/Game.h"
#include "Nelda/LevelCreator.h"
#include "Nelda/Player.h"
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
  GE::GameEngine engine = GE::GameEngine("Nelda");
  GameState gameState = GameState();

  LevelCreator lc = LevelCreator("./src/Nelda/level.txt", 100);
  lc.setGameObject('w', []() { return Wall::create(200, 200, 100); });
  lc.setGameObject('e', [&gameState]() {
    return Enemy::create(TempObject(400, 500), 10, 10, 1, gameState);
  });
  lc.make(engine);

  GE::Player *p = GE::Player::create(gameState);
  p->setup(&engine);

  engine.start();

  return 0;
}
