#include "GameEngine.h"
#include "SoundPlayer.h"
#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char *argv[]) {

    // Initiera SDL för ljud
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL Audio init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // ========= TESTA SOUNDPLAYER =========
    {
        GE::SoundPlayer sound("resources/sounds/sample.wav");

        std::cout << "Spelar sample.wav...\n";
        sound.play();
        SDL_Delay(1500);

        std::cout << "Pausar...\n";
        sound.pause();
        SDL_Delay(1000);

        std::cout << "Spelar igen...\n";
        sound.play();
        SDL_Delay(1500);

        std::cout << "Stoppar...\n";
        sound.stop();
        SDL_Delay(500);
    }
    // =====================================

    GE::GameEngine *ge = new GE::GameEngine();
    ge->start();

    SDL_Quit();
    return 0;
}
