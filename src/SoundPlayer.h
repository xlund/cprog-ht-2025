#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <string>

namespace GE {

class SoundPlayer {
public:
    SoundPlayer(std::string src);
    ~SoundPlayer(); //Behövs destruktor?

    void play();
    void pause();
    void stop();

    std::string getSrc();
    void setSrc(std::string src);

private:
    std::string src {};
    SDL_AudioSpec spec{};
    Uint8* buffer = nullptr;
    Uint32 length = 0;
    SDL_AudioStream* stream = nullptr;

    void loadSound(std::string src); //privat hjälpmetod
};

} 

#endif
