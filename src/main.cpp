#include "GameEngine.h"
#include "SoundPlayer.h"
#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char *argv[]) {

    /*testar ljud här just, inna vi starta spelet*/
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL Audio init error: " << SDL_GetError() << std::endl; //Borde kanske standardisera felmeddelanden?
        return 1;
    }

    
    {
        GE::SoundPlayer sound("resources/sounds/sample.wav");

        std::cout << "Spelar kjells bästa låt\n";
        sound.play();
        SDL_Delay(1500);

        std::cout << "Pausar...\n";
        sound.pause();
        SDL_Delay(1000);

        std::cout << "Spelar kjells bästa låt igen...\n";
        sound.play();
        SDL_Delay(1500);

        std::cout << "Stoppar äntligen kjells bästa låt\n";
        sound.stop();
        SDL_Delay(500);
    }
    /******************************/

    GE::GameEngine *ge = new GE::GameEngine();
    ge->start();

    SDL_Quit();
    return 0;
}
