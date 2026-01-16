#include "Sprite.h"
#include "GameEngine.h"
#include "GameObject.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

GE::Sprite *GE::Sprite::create(int x, int y, int z, int r, std::string src,
                               GE::GameEngine *ge) {
  GE::Sprite *s = new Sprite(x, y, z, r, src, ge);
  ge->addComponent(s);
  return s;
}

GE::Sprite::Sprite(int x, int y, int z, int r, std::string src,
                   GE::GameEngine *ge)
    : Component(ge), x(x), y(y), z(z), rotation(r), srcPath(src) {

  // std::cout << "Creating sprite: " << src << std::endl;
  SDL_Renderer *renderer = GE::GameEngine::getRenderer();
  if (!renderer) {
    // std::cerr << "Renderer is null when creating sprite: " << src << "\n";
    texture = nullptr;
    return;
  }
  texture = IMG_LoadTexture(renderer, src.c_str());
  if (!texture) {
    // std::cerr << "Failed to load texture: " << src << "\n";
    return;
  }

  float w, h;
  SDL_GetTextureSize(texture, &w, &h);
  spriteWidth = static_cast<int>(w);
  spriteHeight = static_cast<int>(h);

  dstRect = {static_cast<float>(x), static_cast<float>(y), w, h};
}

GE::Sprite::~Sprite() {
  if (texture) {
    SDL_DestroyTexture(texture);
  }
  // std::cout<<"GE::Sprite::~Sprite()"<<std::endl;
  gameEngine->removeComponent(this);
}

void GE::Sprite::render() {
  dstRect.x = static_cast<float>(x);
  dstRect.y = static_cast<float>(y);
  dstRect.w = static_cast<float>(spriteWidth);
  dstRect.h = static_cast<float>(spriteHeight);

  SDL_RenderTexture(GameEngine::getRenderer(), texture, nullptr, &dstRect);
}

void GE::Sprite::update() {}

void GE::Sprite::erase() {
  if (texture) {
    SDL_DestroyTexture(texture);
    texture = nullptr;
  }
}

int GE::Sprite::getX() const { return x; }
int GE::Sprite::getY() const { return y; }
int GE::Sprite::getZ() const { return z; }
int GE::Sprite::getHeight() const { return spriteHeight; }
int GE::Sprite::getWidth() const { return spriteWidth; }
int GE::Sprite::getRotation() const { return rotation; }

void GE::Sprite::setX(int v) { x = v; }
void GE::Sprite::setY(int v) { y = v; }
void GE::Sprite::setZ(int v) { z = v; }
void GE::Sprite::setHeight(int v) { spriteHeight = v; }
void GE::Sprite::setWidth(int v) { spriteWidth = v; }
void GE::Sprite::setRotation(int v) { rotation = v; }

std::string GE::Sprite::getSrc() const { return srcPath; }
SDL_Texture *GE::Sprite::getTexture() const { return texture; }
