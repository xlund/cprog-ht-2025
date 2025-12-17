#include "Sprite.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>

GE::Sprite::Sprite(int x, int y, int z, int w, int h, int r, std::string src,
                   SDL_Renderer *renderer)
    : Component(),
    src(src) {
      
  float width;
  float height;
  texture = IMG_LoadTexture(renderer, src.c_str());
  SDL_GetTextureSize(texture, &width, &height);
  rect = {(float)x, (float)y, 1080, 1080};
}

void GE::Sprite::draw(SDL_Renderer *renderer) {
  SDL_RenderTexture(renderer, texture, NULL, &rect);
}

void GE::Sprite::setZ(int z) { this->z = z; }
int GE::Sprite::getZ() { return z; }

std::string GE::Sprite::getSrc() { return src; }

void GE::Sprite::setSrc(const std::string &src) { this->src = src; }

void GE::Sprite::update(SDL_Renderer *renderer) { draw(renderer); }
