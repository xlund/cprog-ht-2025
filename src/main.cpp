#include "Constants.h"
#include "GameEngine/GameEngine.h"

#include "Nelda/Enemy.h"
#include "Nelda/Game.h"
#include "Nelda/LevelCreator.h"
#include "Nelda/Player.h"
#include "Nelda/TempObject.h"
#include "Nelda/Wall.h"

int main(int argc, char *argv[]) {

  GE::GameEngine engine("Nelda");

  GameState gameState;

  LevelCreator level("./src/Nelda/level.txt", 64);

  level.setGameObject('w', []() { return Wall::create(200, 200, 64); });

  level.setGameObject(
    'p',
    [&gameState]() { return Player::create(gameState); }
    );
  level.setGameObject('e', [&gameState]() {
    return Enemy::create(nullptr, 10, 10, 1, gameState);
  });

  Enemy* e = Enemy::create(nullptr,10,10,1,gameState);
  engine.addGameObject(e);
  delete e;

  level.make(engine);

  engine.start();

  return 0;
}
