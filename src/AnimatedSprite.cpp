#include "AnimatedSprite.h"
#include "GameEngine.h"
#include <SDL3_image/SDL_image.h>

GE::AnimatedSprite::AnimatedSprite(int cols, int rows, int frameWidth,
                                   int frameHeight, int x, int y, int z, int r,
                                   std::string src, SDL_Renderer *renderer)
    : GE::Sprite(x, y, z, r, src, renderer), cols(cols), rows(rows),
      frameWidth(frameWidth), frameHeight(frameHeight) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      frames.push_back(SDL_FRect{static_cast<float>(j * frameWidth),
                                 static_cast<float>(i * frameHeight),
                                 static_cast<float>(frameWidth),
                                 static_cast<float>(frameHeight)});
    }
  }
};

void GE::AnimatedSprite::setCurrentAnimation(
    std::vector<std::pair<size_t, size_t>> animation) {
  currentAnimation = animation;
}

void GE::AnimatedSprite::update(SDL_Renderer *renderer) {
  auto currentPair = currentAnimation[index];
  size_t pos = currentPair.second + currentPair.first * cols;
  SDL_FRect src = frames[pos];
  SDL_FRect dst = {(float)x, float(y), static_cast<float>(frameWidth),
                   static_cast<float>(frameHeight)};

  index++;
  if (index >= currentAnimation.size()) {
    index = 0;
  }
  SDL_RenderTexture(renderer, texture, &src, &dst);
}
