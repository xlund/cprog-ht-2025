#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL3/SDL.h>

namespace GE {
class Component {
public:
  virtual void update() = 0;
  int getX() const;
  int getY() const;
  int getRotation() const;
  void setX(const int);
  void setY(const int);
  void setRotation(const int);

protected:
  Component();
  Component(int, int, int);
  Component(const Component&) = delete;
  Component& operator=(const Component&)=delete;
  float x;
  float y;
  float rotation;
};
} // namespace GE
#endif
