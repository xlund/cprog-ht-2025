#include "Sprite.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>

GE::Sprite::Sprite(int x, int y, int z, int r, std::string src,
                   SDL_Renderer *renderer)
    : Component(), srcPath(src) {
  float width;
  float height;
  texture = IMG_LoadTexture(renderer, src.c_str());
  SDL_GetTextureSize(texture, &width, &height);
  spriteWidth = width;
  spriteHeight = height;
  srcRect = {(float)x, (float)y, width, height};
}

void GE::Sprite::draw(SDL_Renderer *renderer) {
  SDL_RenderTexture(renderer, texture, NULL, &srcRect);
}

void GE::Sprite::setZ(int z) { this->z = z; }
int GE::Sprite::getZ() const { return z; }

std::string GE::Sprite::getSrc() const { return srcPath; }

void GE::Sprite::update(SDL_Renderer *renderer) { draw(renderer); }
