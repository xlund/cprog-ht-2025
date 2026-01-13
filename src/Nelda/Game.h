#ifndef GAME_H
#define GAME_H

#include "Score.h"

struct GameState {
  Score score;
  bool gameOver{false};
};

class Game {
public:
  GameState &state() { return state_; }
  void addScore(int points) {
    state_.score.add(points);
    checkWinCondition();
  };
  bool isOver() const;

private:
  int targetScore_{1000};
  GameState state_;
  void checkWinCondition() {
    if (state_.score.value() >= targetScore_) {
      endGame();
    }
  };
  void endGame() { state_.gameOver = true; };
};

#endif
