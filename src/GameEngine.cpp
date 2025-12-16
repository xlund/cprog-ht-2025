#include "GameEngine.h"
#include "../include/Constants.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <list>
#include <vector>
#include "InputManager.h"
#include <iostream>
#include "Text.h"
#include "Component.h"

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
  TTF_Init();
  // Loop
  std::vector<Component *> components;
  Text *text = new GE::Text("Linus", 20, 20);
  text->setColor(255, 255, 255, 255);
  text->draw();
  components.push_back(text);
  auto bgSound = new SoundPlayer("resources/sounds/background.wav", true);
  bgSound->play();
  int x = 0;
  while (true) {

    SDL_RenderClear(renderer);
    Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
    // Process events
    for (GE::Component *component : components) {
      component->update(renderer);
    }
    
    GE::IM::fetchKeys();

    if(GE::IM::isKeyDown("l")){
      text->setRotation(++x);
    }

    if(GE::IM::isKeyPressed("c")){
      SDL_Log("Creating screen component");
      Sprite *sprite = new GE::Sprite(40,40,0,10,10,0,constants::cool_link,renderer);
      components.push_back(sprite);
    }
    if(GE::IM::isKeyReleased("c")){
      SDL_Log("släpte c");
    }

    if(GE::IM::isKeyDown("f")){
      SDL_Log("FPS: %uz", this->getFps());
    }

    if(GE::IM::isKeyDown("q")){
      goto end_loop;
    }
    
    if(GE::IM::isRightMouseDown()){
      SDL_Log("tryckt");
    }
   
    // ppdatera ljudet så det loopar
    if (bgSound)
      bgSound->update();


    long delay = nextTick - SDL_GetTicks();
    if (delay > 0){SDL_Delay(delay);}

    SDL_RenderPresent(renderer);
  }
end_loop:

  // Shutdown
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
} // namespace GE
