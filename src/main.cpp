#include "Constants.h"
#include "GameEngine/GameEngine.h"

#include "GameEngine/InputManager.h"
#include "Nelda/Enemy.h"
#include "Nelda/Game.h"
#include "Nelda/LevelCreator.h"
#include "Nelda/Player.h"
#include "Nelda/Goal.h"
#include "Nelda/Wall.h"

int main(int argc, char *argv[]) {

  GE::GameEngine engine("Nelda");
  engine.setBackgroundColor(0,100,0,255);

  Game game = Game(engine);

  LevelCreator level("./src/Nelda/level.txt", 64);

  level.setGameObject('w', []() { return Wall::create(200, 200, 64); });

  level.setGameObject('g', [&game]() {
    return Goal::create(&game);});


  Player* player = Player::create(game.state());

  level.setGameObject('p', [&player]() { return player;});
  level.setGameObject('e', [&game,&player]() {
    return Enemy::create(player, 1, game.state());
  });

  level.make(engine);

  engine.run();
  engine.shutdown();

  return 0;
}
