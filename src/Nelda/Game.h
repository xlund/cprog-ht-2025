#ifndef GAME_H
#define GAME_H

#include "../GameEngine/GameEngine.h"
#include "Score.h"

struct GameState {
  Score *score;
  bool gameOver{false};
  bool gameWon;   
};

class Game {
public:
  Game(GE::GameEngine &);
  GameState &state();
  void addScore(int points);
  bool isOver() const;
  void winGame();

private:
  int targetScore_{1000};
  GameState state_;
  void checkWinCondition();
  void endGame();
};

#endif
