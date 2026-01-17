#ifndef GAME_H
#define GAME_H

#include "../GameEngine/GameEngine.h"
#include "../GameEngine/SoundPlayer.h"   
#include "Score.h"

class Player;

struct GameState {
  Score *score;
  bool gameOver{false};
  bool gameWon{false};
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

  GE::SoundPlayer *backgroundMusic_{nullptr};  // Bakgrundsljud

  void checkWinCondition();
  void endGame();
};

#endif
