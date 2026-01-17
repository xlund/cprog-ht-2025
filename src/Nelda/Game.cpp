#include "Game.h"
#include "Display.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/InputManager.h"
#include "Enemy.h"
#include "Goal.h"
#include "LevelCreator.h"
#include "Player.h"
#include "Wall.h"
#include <iostream>

Game::Game(GE::GameEngine &ge) : engine_(ge) {
  Display *score = new Display(ge);
  GameState state = GameState{score, false, false};
  state_ = state;
  player_ = Player::create(*this);
}

void Game::loadLevel(const std::string &path) {
  LevelCreator level(path, 64);

  level.setGameObject('w', []() { return Wall::create(200, 200, 64); });

  level.setGameObject('g', [this]() { return Goal::create(this); });

  level.setGameObject('p', [this]() { return player_; });
  level.setGameObject('e',
                      [this]() { return Enemy::create(player_, 1, *this); });

  level.make(engine_);
}

void Game::setup() {


  backgroundMusic_ = new GE::SoundPlayer(
    constants::background_music,
    true);
  backgroundMusic_->play();

  winSound_ = new GE::SoundPlayer(
    constants::win_sound,
    false);

  loadLevel(constants::labyrinth_level_path);

  engine_.setInputCallback([this]() {
    if (GE::InputManager::isKeyPressed("r")) {
      if (state_.gameWon || state_.gameOver) {
        reset();
      }
    }
  });
}


void Game::reset() {
  engine_.clearAll();
  state_.gameOver = false;
  state_.gameWon = false;
  state_.display->reset();

  player_ = Player::create(*this);
  loadLevel(constants::labyrinth_level_path);
  engine_.run();
}

void Game::win() {
  backgroundMusic_->stop();   

  winSound_->play();          

 state_.display->setText(
  "You win! Press 'r' to play this amazing game again."
);

  state_.gameWon = true;
  engine_.pause();
}

GameState &Game::state() { return state_; };

void Game::lose() {
state_.display->setText("The demon got you. You lost. 'r' to restart");  endGame();
}
void Game::endGame() {
  state_.gameOver = true;
    engine_.pause();};
