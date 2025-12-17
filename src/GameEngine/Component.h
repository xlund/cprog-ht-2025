#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL3/SDL.h>

namespace GE {
class Component {
public:
  Component();
  Component(int, int,int);
  virtual void update(SDL_Renderer *renderer) = 0;
  int getX()const;
  int getY()const;
  int getRotation()const;
  void setX(const int);
  void setY(const int);
  void setRotation(const int);


  protected:
  float x;
  float y;
  float rotation;
};
} // namespace GE
#endif
