#ifndef GAME_H
#define GAME_H

#include "../GameEngine/GameEngine.h"
#include "Score.h"

class Player;
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
  void loadLevel(const std::string &path);
  void start();
  void reset();
  Player *player();
  void setup();

private:
  GE::GameEngine &engine_;
  Player *player_;
  int targetScore_{1000};
  GameState state_;
  void checkWinCondition();
  void endGame();
};

#endif
