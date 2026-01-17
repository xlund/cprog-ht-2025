#include "Game.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/InputManager.h"
#include "Enemy.h"
#include "Goal.h"
#include "LevelCreator.h"
#include "Player.h"
#include "Wall.h"
#include <iostream>
#include "StartScreen.h"

Game::Game(GE::GameEngine &ge) : engine_(ge) {
  Score *score = new Score(ge);
  GameState state = GameState{score, false, false};
  state_ = state;
  player_ = Player::create(state_);
}

void Game::loadLevel(const std::string &path) {

  LevelCreator level(path, 64);

  level.setGameObject('w', []() { return Wall::create(200, 200, 64); });

  level.setGameObject('g', [this]() { return Goal::create(this); });

  level.setGameObject('p', [this]() { return player_; });
  level.setGameObject('e',
                      [this]() { return Enemy::create(player_, 1, state()); });

  level.make(engine_);
  float x, y;
  player_->getPos(x, y);
}

void Game::setup() {
  
  StartScreen* startScreen = StartScreen::create();
  engine_.addGameObject(startScreen);

  loadLevel(constants::labyrinth_level_path);
  engine_.setInputCallback([this]() {
    if (GE::InputManager::isKeyPressed("r")) {
      if (state_.gameWon) {
        reset();
      }
    }
  });
}

void Game::reset() {
  engine_.clearAll();
  state_.gameOver = false;
  state_.gameWon = false;
  state_.score->reset();

  player_ = Player::create(state_);
  loadLevel(constants::labyrinth_level_path);
}

void Game::addScore(int points) {
  state_.score->add(points);
  checkWinCondition();
}
void Game::winGame() {
  state_.score->setText("You win! Press 'r' to play this amazing game again.");
  state_.gameWon = true;
  engine_.pause();
}

GameState &Game::state() { return state_; };

void Game::checkWinCondition() {

  if (state_.score->value() >= targetScore_) {
    endGame();
  }
}
void Game::endGame() { state_.gameOver = true; };
