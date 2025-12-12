#include "GameEngine.h"
#include "../include/Constants.h"
#include "ScreenComponent.h"
#include "Sprite.h"
#include "Text.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <algorithm>
#include <vector>
#include "InputManager.h"

namespace GE {

GameEngine::GameEngine(int fps) : fps(fps) {
  window = SDL_CreateWindow("Nelda!", 500, 450, 0);
  renderer = SDL_CreateRenderer(window, nullptr);
}

GameEngine::GameEngine() {
  window = SDL_CreateWindow("Nelda!", 1080, 1080, 0);
  renderer = SDL_CreateRenderer(window, nullptr);
}

GameEngine::~GameEngine() {
  delete bgSound; // Städa ljudet
}

void GameEngine::tick() {}

void GameEngine::setFps(int fps) {
  this->fps = fps;
  this->tickInterval = constants::clockSpeed / this->fps;
}

SDL_Renderer *GameEngine::getRenderer() { return renderer; }
SDL_Window *GameEngine::getWindow() { return window; }
int GameEngine::getFps() { return fps; }

void GameEngine::addScreenComponent(ScreenComponent *component) {
  screenComponents.push_back(component);
}

void GameEngine::removeScreenComponent(ScreenComponent *component) {
  auto it =
      std::find(screenComponents.begin(), screenComponents.end(), component);
  if (it != screenComponents.end())
    screenComponents.erase(it);
}

void GE::GameEngine::start() {
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  TTF_Init();
  // Loop
  std::vector<ScreenComponent *> components;
  Text *text = new GE::Text("Linus", 20, 20);
  components.push_back(text);
  text->setColor(255, 255, 255, 255);
  text->draw();
  bgSound = new SoundPlayer("resources/sounds/background.wav", true);
  bgSound->play();
  int x = 0;
  while (true) {

    SDL_RenderClear(renderer);
    Uint64 nextTick = SDL_GetTicks() + this->tickInterval;
    // Process events
    for (ScreenComponent *component : components) {
      component->update(renderer);
    }
    
    GE::IM::fetchKeys();

    if(GE::IM::isKeyDown("l")){
      text->setRotation(++x);
    }

    if(GE::IM::isKeyPressed("c")){
      SDL_Log("Creating screen component");
      Sprite *sprite =
      new GE::Sprite(renderer, constants::cool_link, 40, 40);
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
   
    // ppdatera ljudet så det loopar
    if (bgSound)
      bgSound->update();


    long delay = nextTick - SDL_GetTicks();
    if (delay > 0){SDL_Delay(delay);}

    SDL_RenderPresent(renderer);
  }
end_loop:
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

  void tytyt(){

  }


} // namespace GE
