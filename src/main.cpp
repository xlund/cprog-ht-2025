#include "Constants.h"
#include "GameEngine/GameEngine.h"

#include "GameEngine/InputManager.h"
#include "Nelda/Enemy.h"
#include "Nelda/Game.h"
#include "Nelda/Goal.h"
#include "Nelda/LevelCreator.h"
#include "Nelda/Player.h"
#include "Nelda/Wall.h"

int main(int argc, char *argv[]) {

  GE::GameEngine engine("Nelda");
  engine.setBackgroundColor(0, 100, 0, 255);

  Game game(engine);
  game.setup();

  engine.run();
  engine.shutdown();

  return 0;
}
