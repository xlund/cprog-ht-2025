#include "Rectangle.h"
#include "GameEngine.h"
namespace GE {

Rectangle::Rectangle(float x, float y, float w, float h, GameEngine *engine)
    : Component(engine, x, y, 0), width_(w), height_(h) {}

Rectangle::Rectangle(float x, float y, float w, float h, Uint8 r, Uint8 g,
                     Uint8 b, Uint8 a, GameEngine *engine)
    : Component(engine, x, y, 0), width_(w), height_(h), r_(r), g_(g), b_(b),
      a_(a) {}

Rectangle *Rectangle::create(float x, float y, float w, float h,
                             GameEngine *engine) {
  Rectangle *rect = new Rectangle(x, y, w, h, engine);
  engine->addComponent(rect);
  return rect;
}

Rectangle *Rectangle::create(float x, float y, float w, float h, Uint8 r,
                             Uint8 g, Uint8 b, Uint8 a, GameEngine *engine) {
  Rectangle *rect = new Rectangle(x, y, w, h, r, g, b, a, engine);
  engine->addComponent(rect);
  return rect;
}

void Rectangle::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  r_ = r;
  g_ = g;
  b_ = b;
  a_ = a;
}

void Rectangle::setSize(float w, float h) {
  width_ = w;
  height_ = h;
}

void Rectangle::update() {}

void Rectangle::render() {
  SDL_Renderer *renderer = gameEngine->getRenderer();
  SDL_SetRenderDrawColor(renderer, r_, g_, b_, a_);

  SDL_FRect rect{x, y, width_, height_};
  SDL_RenderFillRect(renderer, &rect);
}

} // namespace GE
