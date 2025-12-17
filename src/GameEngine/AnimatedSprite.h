#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include "Sprite.h"
#include <vector>

namespace GE {
class AnimatedSprite : public GE::Sprite {
public:
  AnimatedSprite(int cols, int rows, int frameWidth, int frameHeight, int x,
                 int y, int z, int r, std::string src, SDL_Renderer *renderer);
  std::vector<SDL_FRect *> const getFrames();

  using GE::Sprite::update;
  void update(SDL_Renderer *renderer);
  void setCurrentAnimation(std::vector<std::pair<size_t, size_t>>);

private:
  int cols{0};
  int rows{0};
  int frameWidth{0};
  int frameHeight{0};
  int index{0};
  std::vector<std::pair<size_t, size_t>> currentAnimation;
  std::vector<SDL_FRect> frames;
};
} // namespace GE
#endif
