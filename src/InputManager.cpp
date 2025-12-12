#include "InputManager.h"
#include <SDL3/SDL.h>
#include <vector>
#include <string>
#include <stdexcept>


std::vector<SDL_Event> events;
const bool* states;

bool GE::IM::isKeyDown(char key) {
    key = std::tolower(key);
    if (key < 'a' || key > 'z'){
        throw std::invalid_argument("isKeyDown needs an karakter fome a to z");
    }
    SDL_Scancode code = (SDL_Scancode)(SDL_SCANCODE_A + (key - 'a'));
    return states[code];
}

bool isKeyInteracted(unsigned int key,SDL_EventType type){
        for(SDL_Event event : events){
        if(event.type==type && event.key.key == key){
            return true;
        }
    }
    return false;
}

bool GE::IM::isKeyPressed(char key){
    return isKeyInteracted(key,SDL_EVENT_KEY_DOWN);
}

bool GE::IM::isKeyReleased(char key){
    return isKeyInteracted(key,SDL_EVENT_KEY_UP);
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

    states = SDL_GetKeyboardState(NULL);

}
