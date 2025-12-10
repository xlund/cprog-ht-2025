#include "GameEngine.h"
#include "../include/Constants.h"
#include "ScreenComponent.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <vector>

namespace GE {

GameEngine::GameEngine(int fps) : fps(fps) {
    window = SDL_CreateWindow("Nelda!", 500, 500, 0);
    renderer = SDL_CreateRenderer(window, nullptr);
}

GameEngine::GameEngine() {
    window = SDL_CreateWindow("Nelda!", 1080, 1080, 0);
    renderer = SDL_CreateRenderer(window, nullptr);
}

GameEngine::~GameEngine() {
    delete bgSound;       // Städa ljudet
}

void GameEngine::tick() {}

void GameEngine::setFps(int fps) {
    this->fps = fps;
    this->tickInterval = constants::clockSpeed / this->fps;
}

SDL_Renderer* GameEngine::getRenderer() { return renderer; }
SDL_Window* GameEngine::getWindow() { return window; }
int GameEngine::getFps() { return fps; }

void GameEngine::addScreenComponent(ScreenComponent* component) {
    screenComponents.push_back(component);
}

void GameEngine::removeScreenComponent(ScreenComponent* component) {
    auto it = std::find(screenComponents.begin(), screenComponents.end(), component);
    if (it != screenComponents.end())
        screenComponents.erase(it);
}

void GameEngine::start() {

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);

    // starta bakgrundsljudet!!!!
    bgSound = new SoundPlayer("resources/sounds/background.wav", true);
    bgSound->play();

    SDL_Event event{};
    std::vector<ScreenComponent*> components;

    while (true) {
        Uint64 nextTick = SDL_GetTicks() + tickInterval;

        // Uppdatera screen components
        for (auto* c : components)
            c->update();

        // ppdatera ljudet så det loopar
        if (bgSound)
            bgSound->update();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_KEY_DOWN) {

                if (event.key.key == SDLK_Q)
                    goto end_loop;

                if (event.key.key == SDLK_F)
                    SDL_Log("FPS: %d", fps);

                if (event.key.key == SDLK_C) {
                    Sprite* sprite = new Sprite(renderer, constants::cool_link, 40, 40);
                    components.push_back(sprite);
                }

                if (event.key.key == SDLK_UP)
                    setFps(getFps() + 10);

                if (event.key.key == SDLK_DOWN)
                    setFps(getFps() - 10);
            }
        }

        long delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);

        SDL_RenderPresent(renderer);
    }

end_loop:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

} 
