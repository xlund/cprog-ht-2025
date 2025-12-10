#include "GameEngine.h"
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);

    GE::GameEngine game;
    game.start();

    return 0;
}
