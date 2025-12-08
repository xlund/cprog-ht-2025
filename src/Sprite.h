#ifndef SPRITE_H
#define SPRITE_H

#include "ScreenComponent.h"
#include <SDL3/SDL.h>
#include <string>

namespace GE {
class Sprite : public ScreenComponent {
public:
  Sprite(SDL_Renderer *, std::string, int x, int y);
  void erase();
  void draw();
  int getZ();
  void setZ(int);
  std::string getSrc();
  void setSrc(std::string);
  void update();
  SDL_Texture *getTexture();

private:
  std::string src{""};
  int z{0};
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_FRect rect;
};
} // namespace GE

#endif
