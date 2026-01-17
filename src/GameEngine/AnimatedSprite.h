#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "GameEngine.h"
#include "Sprite.h"
#include <vector>

namespace GE {

class AnimatedSprite : public GE::Sprite {
public:
  static AnimatedSprite *create(int cols, int rows, int frameWidth,
                                int frameHeight, int x, int y, int z, int r,
                                std::string src, GE::GameEngine *ge);

  ~AnimatedSprite();

  const std::vector<SDL_FRect> &getFrames() const;

  void update();
  void render();
  void
  setCurrentAnimation(const std::vector<std::pair<size_t, size_t>> &animation);

private:
  AnimatedSprite(int cols, int rows, int frameWidth, int frameHeight, int x,
                 int y, int z, int r, std::string src, GE::GameEngine *ge);
  AnimatedSprite(const AnimatedSprite &) = delete;
  AnimatedSprite &operator=(const AnimatedSprite &) = delete;

  int cols{0};
  int rows{0};
  int frameWidth{0};
  int frameHeight{0};
  size_t index{0};

  std::vector<std::pair<size_t, size_t>> currentAnimation;
  std::vector<SDL_FRect> frames;
};

} // namespace GE

#endif
