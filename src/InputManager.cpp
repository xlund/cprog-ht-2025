#include "InputManager.h"
#include <SDL3/SDL.h>
#include <vector>
#include <string>
#include <stdexcept>


std::vector<SDL_Event> events;

bool GE::IM::isKeyDown(char key) {
    key = std::tolower((unsigned char)key);
    if (key < 'a' || key > 'z'){
        throw std::invalid_argument("isKeyDown needs an karakter fome a to z");
    }

    SDL_Scancode sc = (SDL_Scancode)(SDL_SCANCODE_A + (key - 'a'));

    const bool* state = SDL_GetKeyboardState(NULL);
    bool isPresen = state[sc];
    return state[sc];
}

bool GE::IM::isKeyPressed(char key){
    for(SDL_Event event : events){
        if(event.type==SDL_EVENT_KEY_DOWN && event.key.key == key){
            return true;
        }
    }
    return false;
}
bool GE::IM::isSpecialKeyPressed(std::string key){

}

//kan skapa rray av nedtryckna tangenter
void GE::IM::fetchKeys(){
    events.clear();
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        events.push_back(event);
    }
}
