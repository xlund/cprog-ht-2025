#include "Constants.h"
#include "GameEngine/GameEngine.h"

#include "Nelda/Enemy.h"
#include "Nelda/Game.h"
#include "Nelda/LevelCreator.h"
#include "Nelda/Player.h"
#include "Nelda/Goal.h"
#include "Nelda/Wall.h"

int main(int argc, char *argv[]) {

  GE::GameEngine engine("Nelda");

  Game game = Game(engine);

  LevelCreator level("./src/Nelda/level.txt", 64);

  level.setGameObject('w', [&engine]() { return Wall::create(200, 200, 64,&engine); });

  level.setGameObject('p', [&game, &engine]() { return Player::create(game.state(),&engine); });
  level.setGameObject('e', [&game,&engine]() {
    return Enemy::create(nullptr, 1, game.state(),&engine);
  });

  level.make(engine);

  engine.start();

  return 0;
}
