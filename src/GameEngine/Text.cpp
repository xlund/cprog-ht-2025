#include "Text.h"
#include "../include/Constants.h"
#include "GameEngine.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

GE::Text::Text(std::string text, int x, int y)
    : Component(x, y, 0), str(text),
      font(TTF_OpenFont(constants::STANDARD_FONT.c_str(), 24)),
      fontPath(constants::STANDARD_FONT), fontSize(24), width(100000),
      height(24) {}

GE::Text::Text(std::string text, std::string path, int fontSize, int x, int y)
    : Component(x, y, 0), str(text), font(TTF_OpenFont(path.c_str(), fontSize)),
      fontPath(path), fontSize(fontSize), width(1080), height(fontSize) {}

GE::Text::~Text() {
  if (font) {
    TTF_CloseFont(font);
  }
}

void GE::Text::setString(const std::string &text) { this->str = text; }

void GE::Text::erase() { str = ""; }

std::string GE::Text::getString() const { return this->str; }

void GE::Text::setColor(unsigned char r, unsigned char g, unsigned char b,
                        unsigned char brightnes) {
  color = {r, g, b, brightnes};
}

void GE::Text::setFont(const std::string &path) {
  font = TTF_OpenFont(path.c_str(), fontSize);
}

void GE::Text::setFontSize(const int size) {
  font = TTF_OpenFont(fontPath.c_str(), size);
}

void GE::Text::setWidth(const int w) { width = w; }

void GE::Text::setHeight(const int h) { height = h; }

void GE::Text::draw() { isSeen = true; }

void GE::Text::update() {

  SDL_Renderer *renderer = GE::GameEngine::getRenderer();
  if (str.empty()) {
    return;
  }
  if (!font) {
    throw std::invalid_argument("Font dose not exist");
  }

  if (isSeen) {
    SDL_Surface *surface = TTF_RenderText_Blended_Wrapped(
        font, str.c_str(), str.length(), color, width);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    float texW, texH;
    SDL_GetTextureSize(texture, &texW, &texH);
    int intTexH = static_cast<int>(texH);
    intTexH = 1000;
    int clippedHeight = std::min(height, intTexH);

    // beskär
    SDL_FRect srcRect = {0.0f, 0.0f, static_cast<float>(texW),
                         static_cast<float>(clippedHeight)};
    // ritar det beskärda
    SDL_FRect destRect = {static_cast<float>(x), static_cast<float>(y),
                          static_cast<float>(texW),
                          static_cast<float>(clippedHeight)};

    SDL_RenderTextureRotated(renderer, texture, &srcRect, &destRect, rotation,
                             NULL, SDL_FLIP_NONE);
    SDL_DestroyTexture(texture);
  }
}

void GE::Text::hide() { isSeen = false; }
