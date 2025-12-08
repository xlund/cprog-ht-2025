#include "SoundPlayer.h"
#include <iostream>

namespace GE {

SoundPlayer::SoundPlayer(std::string src) : src(src) {
    loadSound(src);
}


SoundPlayer::~SoundPlayer() {
    if (stream) {
        SDL_DestroyAudioStream(stream);
        stream = nullptr;
    }

    if (buffer) {
        SDL_free(buffer);
        buffer = nullptr; //kanske onödigt?
    }
}

void SoundPlayer::loadSound(std::string src) {
    if (!SDL_LoadWAV(src.c_str(), &spec, &buffer, &length)) {
        std::cerr << "Kunde inte ladda ljudfil '" << src  //Felmeddelande bör kanske vara på engelska?
                  << "': " << SDL_GetError() << std::endl;
        return;
    }

    stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
                                       &spec, nullptr, nullptr);

    if (!stream) {
        std::cerr << "Kunde inte skapa audio stream: " //Felmeddelande bör kanske vara på engelska?
                  << SDL_GetError() << std::endl;
        SDL_free(buffer);
        buffer = nullptr;
    }
}

void SoundPlayer::play() {
    if (!stream || !buffer) return;

    SDL_ClearAudioStream(stream);
    SDL_PutAudioStreamData(stream, buffer, length);
    SDL_ResumeAudioStreamDevice(stream);
}

void SoundPlayer::pause() {
    if (!stream) return;

    SDL_PauseAudioStreamDevice(stream);
}

void SoundPlayer::stop() {
    if (!stream) return;

    SDL_PauseAudioStreamDevice(stream);
    SDL_ClearAudioStream(stream);
}


std::string SoundPlayer::getSrc() {
    return src;
}

void SoundPlayer::setSrc(std::string src) {
    this->src = src;

    // Rensa tidigare ljud - kanske onödigt?
    if (stream) SDL_DestroyAudioStream(stream);
    if (buffer) SDL_free(buffer);

    stream = nullptr;
    buffer = nullptr;

    loadSound(src);
}

} 
