#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include <SDL3/SDL.h>
#include <string>

namespace GE {
class Sprite : public GE::Component {
public:
  Sprite(int x, int y, int z, int r, std::string src, SDL_Renderer *renderer);
  int getX() const;
  int getY() const;
  int getZ() const;
  int getHeight() const;
  int getWidth() const;
  int getRotation() const;
  void setX(const int);
  void setY(const int);
  void setZ(const int);
  void setHeight(const int);
  void setWidth(const int);
  void setRotation(const int);
  void erase();
  void draw(SDL_Renderer *renderer);
  void update(SDL_Renderer *renderer);
  std::string getSrc() const;
  SDL_Texture *getTexture() const;

protected:
  int x{0};
  int y{0};
  int z{0};
  int spriteHeight{50};
  int spriteWidth{50};
  int rotation{0};
  std::string srcPath{""};
  SDL_Texture *texture;
  SDL_FRect srcRect;
};

} // namespace GE
#endif
