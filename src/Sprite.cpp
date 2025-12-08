#include "Sprite.h"
#include "ScreenComponent.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>

GE::Sprite::Sprite(SDL_Renderer *renderer, std::string src, int x, int y)
    : renderer(renderer), src(src) {
  float width;
  float height;
  SDL_Texture *texture = IMG_LoadTexture(renderer, src.c_str());
  SDL_Log("w: %f, h: %f", width, height);
  SDL_GetTextureSize(texture, &width, &height);
  SDL_FRect rect = {(float)x, (float)y, 1080, 1080};
  SDL_RenderTexture(renderer, texture, NULL, &rect);
}

void GE::Sprite::setZ(int z) { this->z = z; }
int GE::Sprite::getZ() { return z; }

std::string GE::Sprite::getSrc() { return src; }

void GE::Sprite::setSrc(std::string src) { this->src = src; }

void GE::Sprite::update() {}
