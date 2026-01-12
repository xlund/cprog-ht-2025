#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include <SDL3/SDL.h>
#include <string>

namespace GE {

class Sprite : public GE::Component {
public:
  Sprite(int x, int y, int z, int r, std::string src);
  ~Sprite();

  int getX() const;
  int getY() const;
  int getZ() const;
  int getHeight() const;
  int getWidth() const;
  int getRotation() const;

  void setX(int);
  void setY(int);
  void setZ(int);
  void setHeight(int);
  void setWidth(int);
  void setRotation(int);

  void erase();
  void draw();
  void update();

  std::string getSrc() const;
  SDL_Texture *getTexture() const;

protected:
  int x{0};
  int y{0};
  int z{0};
  int spriteHeight{0};
  int spriteWidth{0};
  int rotation{0};

  std::string srcPath;
  SDL_Texture *texture{nullptr};
  SDL_FRect dstRect;
};

} // namespace GE

#endif
