#ifndef SCORE_H
#define SCORE_H

#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Text.h"

class Display {
public:
  Display(GE::GameEngine &);
  void reset();
  GE::Text *getText() const;
  void setText(const std::string& text);

private:
  GE::Text *text_;
};

#endif
