#ifndef GAME_H
#define GAME_H

#include "../GameEngine/GameEngine.h"
#include "Display.h"

class Player;
struct GameState {
  Display *display;
  bool gameOver{false};
  bool gameWon;
};


class Game {
public:
  Game(GE::GameEngine &);
  GameState &state();
  void addScore(int points);
  bool isOver() const;
  void win();
  void loadLevel(const std::string &path);
  void start();
  void reset();
  Player *player();
  void setup();
  void lose();

private:
  GE::GameEngine &engine_;
  Player *player_;
  int targetScore_{1000};
  GameState state_;
  void checkWinCondition();
  void endGame();
};

#endif
