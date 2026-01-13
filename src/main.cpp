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

  LevelCreator level("./src/Nelda/level2.txt", 100);

  level.setGameObject('w', []() { return Wall::create(200, 200, 100); });

  level.setGameObject('p',
                      [&gameState]() { return GE::Player::create(gameState); });

  level.setGameObject('e', [&gameState]() {
    return Enemy::create(TempObject(400, 500), 10, 10, 1, gameState);
  });

  level.make(engine);

  engine.start();

  return 0;
}
