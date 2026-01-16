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

void GE::GameEngine::setBackgroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
  backgroundColor = {r,g,b,a};
}

bool GE::GameEngine::tick() {

  if(GE::InputManager::isKeyPressed("l")){
    std::cout << "GameObjects: " << gameObjects.size() << "  components: "<<components.size();
  }

  Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
  GE::InputManager::fetchKeys();

  SDL_SetRenderDrawColor(renderer, backgroundColor.r,backgroundColor.g,backgroundColor.b,backgroundColor.a);
  SDL_RenderClear(renderer);

  // Process events
  for (GE::GameObject *object : gameObjects) {
    object->update();
  }
  for (GE::Component *component : components) {
    component->update();
  }

  if (GE::InputManager::isKeyPressed("q")) {
    return false;
  }

  long delay = nextTick - SDL_GetTicks();
  if (delay > 0)
    SDL_Delay(delay);

  // Update objects
  // Render Changes
  SDL_RenderPresent(renderer);
  return true;
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
  gameObjects.push_back(object);
}

void GE::GameEngine::removeGameObject(GE::GameObject *object) {
  auto i = std::find(gameObjects.begin(), gameObjects.end(), object);
  gameObjects.erase(i);
}

void GE::GameEngine::start() {

  // Loop
  for (GE::GameObject *object : gameObjects) {
    object->setup(this);
  }

  while (tick()) {
    gameObjectCleanUp();
  }

  for(GameObject* go : gameObjects){
    go->setToDelete();
  }

  gameObjectCleanUp();

  //std::cout<<components.size();

  gameObjects.clear();

  // Shutdown
  TTF_Quit();
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void GE::GameEngine::gameObjectCleanUp(){
    gameObjects.erase(std::remove_if(gameObjects.begin(),gameObjects.end(),[](GameObject* go){
      if(go->isDeleteable()){
        delete go;
        return true;
      }
      return false;
    }),
  gameObjects.end());
}
