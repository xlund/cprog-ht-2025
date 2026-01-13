
#include "Score.h"
void Score::add(int score) { score_ += score; }

void Score::reset() { score_ = 0; }

int Score::value() const { return score_; }
