#ifndef SPRITE_H
#define SPRITE_H

#include "ScreenComponent.h"
#include <string>

namespace GE {
  class Sprite : public ScreenComponent {
    public:
      void erase();
      void draw();
    private:
      std::string src;
  };
}

#endif
