
#include "Display.h"
#include "../GameEngine/Text.h"
#include <string>

void Display::reset() { text_->erase(); }

GE::Text *Display::getText() const { return text_; }

void Display::setText(const std::string &text) { text_->setString(text); }

Display::Display(GE::GameEngine &ge) {
  text_ = GE::Text::create("", 10, 600,
                           &ge);
  text_->setColor(255, 255, 255, 255);
  text_->draw(); // This sets isSeen = true
}
