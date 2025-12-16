#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <string>

namespace GE {

class SoundPlayer {
public:
    SoundPlayer(std::string src, bool loop = false);
    ~SoundPlayer(); 

    void play();
    void pause();
    void stop();
    void update();                      // Håller loopande ljud vid liv

    std::string getSrc();
    void setSrc(std::string src);

private:
    std::string src {}; 
    SDL_AudioSpec spec{}; 
    Uint8* buffer = nullptr;
    Uint32 length = 0;
    SDL_AudioStream* stream = nullptr;

    bool loop = false;                  // Loop-flagga

    void loadSound(std::string src);    // Privat hjälpmetod
};

}

#endif
