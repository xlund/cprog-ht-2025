#include "GameEngine.h"
#include "../include/Constants.h"
#include "Hitbox.h"
#include "InputManager.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

SDL_Renderer *GE::GameEngine::renderer = nullptr;

void GE::GameEngine::setRenderer(SDL_Renderer *r) { renderer = r; }

GE::GameEngine::GameEngine(int fps, std::string windowName) : fps(fps) {
  window = SDL_CreateWindow(windowName.c_str(), constants::gScreenWidth,
                            constants::gScreenHeight, 0);
  SDL_Renderer *r = SDL_CreateRenderer(window, NULL);
  GE::GameEngine::setRenderer(r);

  if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) || !TTF_Init()) {
    std::cerr << SDL_GetError() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}
GE::GameEngine::GameEngine(std::string windowName) {
  window = SDL_CreateWindow(windowName.c_str(), constants::gScreenWidth,
                            constants::gScreenHeight, 0);
  SDL_Renderer *r = SDL_CreateRenderer(window, NULL);
  GE::GameEngine::setRenderer(r);

  if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) || !TTF_Init()) {
    std::cerr << SDL_GetError() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

void GE::GameEngine::setBackgroundColor(unsigned char r, unsigned char g,
                                        unsigned char b, unsigned char a) {
  backgroundColor = {r, g, b, a};
}

void GE::GameEngine::setFps(const int fps) {
  this->fps = fps;
  this->tickInterval = constants::clockSpeed / this->fps;
}

SDL_Renderer *GE::GameEngine::getRenderer() { return renderer; }

int GE::GameEngine::getFps() const { return fps; }

void GE::GameEngine::addComponent(GE::Component *component) {
  components.push_back(component);
}

void GE::GameEngine::removeComponent(GE::Component *component) {
  auto i = std::find(components.begin(), components.end(), component);
  components.erase(i);
}

void GE::GameEngine::addGameObject(GE::GameObject *object) {
  object->setup(this);
  gameObjects.push_back(object);
}

void GE::GameEngine::removeGameObject(GE::GameObject *object) {
  auto i = std::find(gameObjects.begin(), gameObjects.end(), object);
  gameObjects.erase(i);
}

void GE::GameEngine::run() {
  state_ = GameState::Running;
  while (state_ != GameState::Stopped) {
    Uint64 frameStart = SDL_GetTicks();
    GE::InputManager::fetchKeys();
    handleGameKeys();
    update();
    render();
    capFrameRate(frameStart);
  }
}

void GE::GameEngine::setInputCallback(std::function<void()> cb) {
  inputCallback_ = cb;
}

void GE::GameEngine::handleGameKeys() {

  if (GE::InputManager::isKeyPressed("p")) {
    if (state_ == GameState::Paused)
      resume();
    else if (state_ == GameState::Running)
      pause();
  }

  if (GE::InputManager::isKeyPressed("q")) {
    state_ = GE::GameState::Stopped;
  }

  if (inputCallback_)
    inputCallback_();
}

void GE::GameEngine::clearAll() {
  clearGameObjects();
  clearComponents();
}

SDL_FRect GE::GameEngine::createRect(float x, float y, float w, float h,
                                     Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  SDL_Renderer *renderer = getRenderer();
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_FRect rect{x, y, w, h};
  SDL_RenderFillRect(renderer, &rect);
  return rect;
}

void GE::GameEngine::update() {
  if (state_ != GameState::Running)
    return;
  for (GE::GameObject *object : gameObjects)
    object->update();

  for (GE::Component *component : components)
    component->update();

  gameObjectCleanUp();
}

void GE::GameEngine::setup() {
  for (GE::GameObject *object : gameObjects)
    object->setup(this);
}

void GE::GameEngine::render() {
  SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g,
                         backgroundColor.b, backgroundColor.a);
  SDL_RenderClear(renderer);
  for (auto ge : gameObjects) {
    ge->render();
  }
  for (auto comp : components) {
    comp->render();
  }
  SDL_RenderPresent(renderer);
}

void GE::GameEngine::pause() { state_ = GameState::Paused; }

void GE::GameEngine::resume() { state_ = GameState::Running; }

void GE::GameEngine::stop() { state_ = GameState::Stopped; }

GE::GameState GE::GameEngine::state() const { return state_; }

void GE::GameEngine::clearGameObjects() {
  for (auto *obj : gameObjects)
    delete obj;
  gameObjects.clear();
}

void GE::GameEngine::clearComponents() {
  for (auto *comp : components)
    delete comp;

  components.clear();
}

void GE::GameEngine::capFrameRate(Uint64 frameStart) {
  Uint64 frameTime = SDL_GetTicks() - frameStart;
  if (frameTime < tickInterval) {
    SDL_Delay(tickInterval - frameTime);
  }
}
void GE::GameEngine::shutdown() {
  for (GameObject *go : gameObjects)
    go->setToDelete();
  gameObjectCleanUp();
  gameObjects.clear();

  TTF_Quit();
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void GE::GameEngine::gameObjectCleanUp() {
  gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(),
                                   [](GameObject *go) {
                                     if (go->isDeleteable()) {
                                       delete go;
                                       return true;
                                     }
                                     return false;
                                   }),
                    gameObjects.end());
}
