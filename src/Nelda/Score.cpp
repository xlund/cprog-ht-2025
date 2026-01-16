
#include "Score.h"
#include "../GameEngine/Text.h"
#include <algorithm>
#include <iostream>
#include <string>
void Score::add(int score) {
  score_ += score;
  text_->setString("Score: " + std::to_string(score_));
}

void Score::reset() { score_ = 0; }

GE::Text *Score::getText() const { return text_; }

int Score::value() const { return score_; }

void Score::setText(const std::string& text) {
    text_->setString(text);
}

Score::Score(GE::GameEngine &ge) {
  std::cout << "Create score display\n";
  text_ = GE::Text::create("Score: " + std::to_string(score_), 10, 600);
  text_->setColor(255, 255, 255, 255);
  text_->draw();
  ge.addComponent(text_);
}
