#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL3/SDL.h>

namespace GE{
  class GameEngine;
}

namespace GE {

class Component {
public:
  virtual void update() = 0;
  virtual ~Component();
  int getX() const;
  int getY() const;
  int getRotation() const;
  void setX(const int);
  void setY(const int);
  void setRotation(const int);

protected:
  Component(GE::GameEngine*);
  Component(GE::GameEngine*,float, float, float);
  Component(const Component&) = delete;
  Component& operator=(const Component&)=delete;
  float x;
  float y;
  float rotation;
  GE::GameEngine* gameEngine;
};
} // namespace GE
#endif
