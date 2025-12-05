#ifndef BUTTON_H
#define BUTTON_H

#include "Text.h"
#include <functional>
namespace GameEngine {
  class Button : public Text {
    public:
      void onClick(std::function<void()>);
      void onExit(std::function<void()>);
  };
}

#endif
