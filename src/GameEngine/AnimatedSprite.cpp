#include "AnimatedSprite.h"
#include "GameEngine.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

GE::AnimatedSprite* GE::AnimatedSprite::create(int cols, int rows, int frameWidth, int frameHeight, int x,
                 int y, int z, int r, std::string src, GE::GameEngine* ge){
    GE::AnimatedSprite* as = new GE::AnimatedSprite(cols,rows,frameWidth,frameHeight,x,y,z,r,src,ge);
    ge->addComponent(as);
    return as;
}



GE::AnimatedSprite::AnimatedSprite(int cols, int rows, int frameWidth,
                                   int frameHeight, int x, int y, int z, int r,
                                   std::string src, GE::GameEngine* ge)
    : GE::Sprite(x, y, z, r, src,ge), cols(cols), rows(rows),
      frameWidth(frameWidth), frameHeight(frameHeight) {

  frames.reserve(cols * rows);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      frames.push_back(SDL_FRect{static_cast<float>(j * frameWidth),
                                 static_cast<float>(i * frameHeight),
                                 static_cast<float>(frameWidth),
                                 static_cast<float>(frameHeight)});
    }
  }
}

GE::AnimatedSprite::~AnimatedSprite(){
  gameEngine->removeComponent(this);
}

const std::vector<SDL_FRect> &GE::AnimatedSprite::getFrames() const {
  return frames;
}

void GE::AnimatedSprite::setCurrentAnimation(
    const std::vector<std::pair<size_t, size_t>> &animation) {
  currentAnimation = animation;
  index = 0;
}

void GE::AnimatedSprite::update() {
  if (currentAnimation.empty()) {
    return;
  }

  auto [row, col] = currentAnimation[index];
  size_t pos = col + row * cols;

  if (pos >= frames.size()) {
    return;
  }

  SDL_FRect src = frames[pos];
  SDL_FRect dst{static_cast<float>(x), static_cast<float>(y),
                static_cast<float>(frameWidth),
                static_cast<float>(frameHeight)};

  SDL_Renderer *renderer = GE::GameEngine::getRenderer();
  SDL_RenderTexture(renderer, texture, &src, &dst);

  index++;
  if (index >= currentAnimation.size()) {
    index = 0;
  }
}
