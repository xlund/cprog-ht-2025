#ifndef GAME_H
#define GAME_H

#include "../GameEngine/GameEngine.h"
#include "../GameEngine/SoundPlayer.h"   
#include "Display.h"

class Player;

struct GameState {
  Display *display;
  bool gameOver{false};
  bool gameWon{false};
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

  GE::SoundPlayer *backgroundMusic_{nullptr};  // Bakgrundsljud

  void checkWinCondition();
  void endGame();
};

#endif
