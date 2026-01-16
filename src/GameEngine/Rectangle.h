#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Component.h"
#include <SDL3/SDL.h>

namespace GE {

class Rectangle : public Component {
public:
  static Rectangle *create(float x, float y, float w, float h,
                           GameEngine *engine);
  static Rectangle *create(float x, float y, float w, float h, Uint8 r, Uint8 g,
                           Uint8 b, Uint8 a, GameEngine *engine);

  void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
  void setSize(float w, float h);

  void update() override;
  void render() override;

private:
  Rectangle(float x, float y, float w, float h, GameEngine *engine);
  Rectangle(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b,
            Uint8 a, GameEngine *engine);

  float width_, height_;
  Uint8 r_{255}, g_{255}, b_{255}, a_{255};
};

} // namespace GE

#endif
