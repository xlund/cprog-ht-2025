#include "Game.h"
#include "../GameEngine/GameEngine.h"
#include <iostream>

Game::Game(GE::GameEngine &ge) {
  std::cout << "Creating Game\n";
  Score *score = new Score(ge);
  GameState state = GameState{
    score,
    false,
    false
};
  state_ = state;
}

void Game::addScore(int points) {
  state_.score->add(points);
  checkWinCondition();
}
void Game::winGame() {
    state_.gameWon = true;
    state_.gameOver = true;

    state_.score->setText("YOU WIN!");
}

GameState &Game::state() { return state_; };

void Game::checkWinCondition() {

  if (state_.score->value() >= targetScore_) {
    endGame();
  }
}
void Game::endGame() { state_.gameOver = true; };
