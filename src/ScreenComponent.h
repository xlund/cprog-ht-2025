#ifndef SCREEN_COMPONENT_H
#define SCREEN_COMPONENT_H

namespace GameEngine {
  class ScreenComponent {
    public:
      int getX();
      void setX();
      void setY();
      int getY();
      int getHeight();
      int getWidth();
      int getRotation();
      void setHeight();
      void setWidth();
      void setRotiation();
      virtual void tick();
    protected:
      int x;
      int y;
      int height;
      int width;
      int rotation;
    private:
  };
}

#endif
