#ifndef SCREEN_COMPONENT_H
#define SCREEN_COMPONENT_H
#include <SDL3/SDL.h>

namespace GE {
class ScreenComponent {
public:
  ScreenComponent();
  ScreenComponent(int x, int y, int h, int w, int r);
  int getX();
  int getY();
  int getHeight();
  int getWidth();
  int getRotation();
  void setX(int);
  void setY(int);
  void setHeight(int);
  void setWidth(int);
  void setRotation(int);
  virtual void update(SDL_Renderer*) = 0;

protected:
  int x{0};
  int y{0};
  int height{50};
  int width{50};
  int rotation{0};

private:
};

} // namespace GE
#endif
