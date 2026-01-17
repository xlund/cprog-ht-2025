#include "Constants.h"
#include "GameEngine/GameEngine.h"
#include "Nelda/StartScreen.h"
#include "Nelda/Game.h"

int main(int argc, char *argv[]) {

  GE::GameEngine engine(constants::game_name);
  engine.setBackgroundColor(0, 100, 0, 255);

  Game game(engine);

  game.setup();
  StartScreen startScreen;
  if(startScreen.show(&engine)){
    engine.run();
  }
    engine.shutdown();
  


  return 0;
}
