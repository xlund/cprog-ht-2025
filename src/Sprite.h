#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include <SDL3/SDL.h>
#include <string>

namespace GE {
class Sprite : public GE::Component {
public:
  Sprite(int x, int y, int z, int h, int w, int r, std::string src,
         SDL_Renderer *renderer);
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
  void erase();
  void draw(SDL_Renderer *renderer);
  void update(SDL_Renderer *renderer);
  int getZ();
  void setZ(int);
  std::string getSrc();
  void setSrc(std::string);
  SDL_Texture *getTexture();
  std::string src{""};

protected:
  int x{0};
  int y{0};
  int z{0};
  int height{50};
  int width{50};
  int rotation{0};
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_FRect rect;
};

} // namespace GE
#endif