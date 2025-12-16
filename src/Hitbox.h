#ifndef HITBOX_H
#define HITBOX_H

#include "ScreenComponent.h"
#include "Sprite.h"
#include <functional>
namespace GE {
  class Hitbox: public ScreenComponent {
    public:
      Sprite onEnter(std::function<void()>);
      Sprite onExit(std::function<void()>);
    private:
      int height;
      int width;
      std::function<void()> func;
  };
}

#endif
