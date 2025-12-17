#include "GameEngine.h"
#include "../include/Constants.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <list>
#include <vector>
#include "Hitbox.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Text.h"

GE::GameEngine::GameEngine(int fps) : fps(fps) {
  window = SDL_CreateWindow("Nelda!", 500, 500, 0);
  renderer = SDL_CreateRenderer(window, NULL);
}
GE::GameEngine::GameEngine() {
  window = SDL_CreateWindow("Nelda!", 1080, 1080, 0);
  renderer = SDL_CreateRenderer(window, NULL);
}

void GE::GameEngine::tick() {}

void GE::GameEngine::setFps(int fps) {
  this->fps = fps;
  this->tickInterval = constants::clockSpeed / this->fps;
}

SDL_Renderer *GE::GameEngine::getRenderer() { return renderer; }

SDL_Window *GE::GameEngine::getWindow() { return window; }

int GE::GameEngine::getFps() { return fps; }

void GE::GameEngine::addScreenComponent(GE::Component *component) {
  components.push_back(component);
}

void GE::GameEngine::removeScreenComponent(GE::Component *component) {
  auto i = std::find(components.begin(), components.end(), component);
  components.erase(i);
}

void GE::GameEngine::start() {
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  // Loop
  std::vector<GE::Component *> components;
  std::vector<GE::GameObject *> objects;

  for(GameObject* object : objects){
    object->setup();
  }

  while (true) {
    Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
    GE::InputManager::fetchKeys();

    // Process events
    for(GameObject* object : objects){
      object->update();
    }
    for (GE::Component *component : components) {
      component->update(renderer);
    }
    
    if(GE::InputManager::isKeyPressed("c")){
      SDL_Log("Creating screen component");
      Sprite *sprite = new GE::Sprite(0, 0, 0, 1080, 1080, 0,constants::cool_link, renderer);
      components.push_back(sprite);
      SDL_Log("Len: %ld", components.size());
    }

    if(GE::InputManager::isKeyPressed("q")){
      goto end_loop;
    }

    
 
    long delay = nextTick - SDL_GetTicks();
    if (delay > 0)
    SDL_Delay(delay);
    
    // Update objects
    // Render Changes
    SDL_RenderPresent(renderer);
  }
end_loop:

  // Shutdown
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  
}

void GE::GameEngine::Hiting(Hitbox* other){
  SDL_Log("i");
}

void GE::GameEngine::Exiting(Hitbox* other){
  SDL_Log("ut");
}

