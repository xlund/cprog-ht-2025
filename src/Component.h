#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL3/SDL.h>

namespace GE {
class Component {
public:
  Component();
  virtual void update(SDL_Renderer *renderer) = 0;
};
} // namespace GE
#endif
