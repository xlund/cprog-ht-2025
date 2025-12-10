#include "SoundPlayer.h"
#include <iostream>

namespace GE {

SoundPlayer::SoundPlayer(std::string src, bool loop)
    : src(src), loop(loop)
{
    loadSound(src);
}

SoundPlayer::~SoundPlayer() {
    if (stream) {
        SDL_DestroyAudioStream(stream);
        stream = nullptr;
    }

    if (buffer) {
        SDL_free(buffer);
        buffer = nullptr;
    }
}

void SoundPlayer::loadSound(std::string src) {
    if (!SDL_LoadWAV(src.c_str(), &spec, &buffer, &length)) {
        std::cerr << "Could not load sound '" << src
                  << "': " << SDL_GetError() << std::endl;
        return;
    }

    stream = SDL_OpenAudioDeviceStream(
        SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
        &spec,
        nullptr,
        nullptr
    );

    if (!stream) {
        std::cerr << "Could not create audio stream: "
                  << SDL_GetError() << std::endl;
        SDL_free(buffer);
        buffer = nullptr;
        return;
    }
}

void SoundPlayer::play() {
    if (!stream || !buffer) return;

    SDL_ClearAudioStream(stream);

    // Första laddningen av ljudet
    SDL_PutAudioStreamData(stream, buffer, length);

    // Om loop → lägg in extra så det inte blir tomt direkt
    if (loop) {
        SDL_PutAudioStreamData(stream, buffer, length);
        SDL_PutAudioStreamData(stream, buffer, length);
    }

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

void SoundPlayer::update() {
    if (!loop || !stream) return;

    // Hur många bytes är kvar i streamens buffert?
    int available = SDL_GetAudioStreamAvailable(stream);

    // SDL3 har nu annat ätt att beräkna bytes per sample
    int bytesPerSample = SDL_AUDIO_BYTESIZE(spec.format);
    int frameSize = bytesPerSample * spec.channels;

    // När bufferten börjar bli liten → fyll på. Lagom mycket?
    if (available < frameSize * 4) {
        SDL_PutAudioStreamData(stream, buffer, length);
    }
}

std::string SoundPlayer::getSrc() {
    return src;
}

void SoundPlayer::setSrc(std::string src) {
    this->src = src;

    if (stream) SDL_DestroyAudioStream(stream);
    if (buffer) SDL_free(buffer);

    stream = nullptr;
    buffer = nullptr;

    loadSound(src);
}

} // namespace GE
