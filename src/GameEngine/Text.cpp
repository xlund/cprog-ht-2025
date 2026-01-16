#include "Text.h"
#include "../include/Constants.h"
#include "GameEngine.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>

GE::Text *GE::Text::create(std::string text, int x, int y, GE::GameEngine *ge) {
  GE::Text *t = new Text(text, x, y, ge);
  ge->addComponent(t);
  return t;
}

GE::Text *GE::Text::create(std::string text, std::string path, int fontSize,
                           int x, int y, GE::GameEngine *ge) {
  GE::Text *t = new Text(text, path, fontSize, x, y, ge);
  ge->addComponent(t);
  return t;
}

GE::Text::Text(std::string text, int x, int y, GE::GameEngine *ge)
    : Component(ge, x, y, 0), engine_(ge), str(text),
      font(TTF_OpenFont(constants::STANDARD_FONT.c_str(), 24)),
      fontPath(constants::STANDARD_FONT), fontSize(24), width(100000),
      height(24) {}

GE::Text::Text(std::string text, std::string path, int size, int x, int y,
               GE::GameEngine *ge)
    : Component(ge, x, y, 0), engine_(ge), str(text),
      font(TTF_OpenFont(path.c_str(), size)), fontPath(path), fontSize(size),
      width(1080), height(size) {}

GE::Text::~Text() {
  if (font) {
    TTF_CloseFont(font);
  }
  gameEngine->removeComponent(this);
}

void GE::Text::setString(const std::string &text) {
  if (str == text)
    return;
  str = text;
  shouldUpdate = true;
}

std::string GE::Text::getString() const { return str; }

void GE::Text::setColor(unsigned char r, unsigned char g, unsigned char b,
                        unsigned char a) {
  color = {r, g, b, a};
}

void GE::Text::setFont(const std::string &path) {
  font = TTF_OpenFont(path.c_str(), fontSize);
  fontPath = path;
}

void GE::Text::setFontSize(int size) {
  fontSize = size;
  font = TTF_OpenFont(fontPath.c_str(), size);
}

void GE::Text::setWidth(int w) { width = w; }

void GE::Text::setHeight(int h) { height = h; }

void GE::Text::draw() { isSeen = true; }

void GE::Text::hide() { isSeen = false; }

void GE::Text::erase() { str.clear(); }

void GE::Text::update() {
  if (!isSeen || str.empty())
    return;
  if (!font)
    throw std::invalid_argument("Font does not exist");

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

    int clippedHeight = std::min(height, static_cast<int>(texH));

    SDL_FRect srcRect{0.f, 0.f, texW, static_cast<float>(clippedHeight)};
    SDL_FRect destRect{static_cast<float>(x), static_cast<float>(y), texW,
                       static_cast<float>(clippedHeight)};

    SDL_RenderTextureRotated(renderer, texture, &srcRect, &destRect, rotation,
                             nullptr, SDL_FLIP_NONE);
    SDL_DestroyTexture(texture);
  }
}

void GE::Text::render() {
  if (!isSeen || str.empty())
    return;

  rebuildTexture();

  int clippedHeight = std::min(height, static_cast<int>(textH));

  SDL_FRect srcRect{0.f, 0.f, static_cast<float>(textW),
                    static_cast<float>(clippedHeight)};
  SDL_FRect destRect{static_cast<float>(x), static_cast<float>(y),
                     static_cast<float>(textW),
                     static_cast<float>(clippedHeight)};

  SDL_RenderTextureRotated(engine_->getRenderer(), texture, &srcRect, &destRect,
                           rotation, nullptr, SDL_FLIP_NONE);
}

void GE::Text::rebuildTexture() {
  if (!font)
    throw std::invalid_argument("Font does not exist");

  SDL_Renderer *renderer = GE::GameEngine::getRenderer();

  if (texture) {
    SDL_DestroyTexture(texture);
    texture = nullptr;
  }

  SDL_Surface *surface = TTF_RenderText_Blended_Wrapped(
      font, str.c_str(), str.length(), color, width);

  if (!surface)
    throw std::runtime_error(SDL_GetError());

  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_DestroySurface(surface);

  SDL_GetTextureSize(texture, &textW, &textH);
  shouldUpdate = false;
}
