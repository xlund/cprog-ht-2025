#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL3/SDL.h>
#include <vector>
#include "ScreenComponent.h"
#include "SoundPlayer.h"

namespace GE {

class GameEngine {
public:
    GameEngine(int fps);
    GameEngine();
    ~GameEngine();

    void start();
    void tick();
    void setFps(int fps);

    SDL_Renderer* getRenderer();
    SDL_Window* getWindow();
    int getFps();

    void addScreenComponent(ScreenComponent* component);
    void removeScreenComponent(ScreenComponent* component);

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int fps = 60;
    int tickInterval = 1000 / 60;

    std::vector<ScreenComponent*> screenComponents;

    GE::SoundPlayer* bgSound = nullptr;   // Bakgrundsljud
};

}

#endif
