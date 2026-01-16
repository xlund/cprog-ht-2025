#ifndef SCORE_H
#define SCORE_H

#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Text.h"

class Score {
public:
  Score(GE::GameEngine &);
  void add(int score);
  int value() const;
  void reset();
  GE::Text display();
  GE::Text *getText() const;

private:
  int score_{0};
  GE::Text *text_;
};

#endif
