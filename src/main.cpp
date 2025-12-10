#include "GameEngine.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <chrono>
#include <iostream>
#include <thread>
int main(int argc, char *argv[]) {
  GE::GameEngine *ge = new GE::GameEngine();

  ge->start();
}
