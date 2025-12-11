#include "InputManager.h"
#include <SDL3/SDL.h>
#include <vector>


std::vector<SDL_Event> events;

bool GE::isKeyPressed(unsigned int input){

    for(SDL_Event ev : events){
        if(ev.type == SDL_EVENT_KEY_DOWN && ev.key.key == input){
            return true;
        }
    }

    return false;
}
//kan skapa rray av nedtryckna tangenter
void GE::fetchKeys(){
    events.clear();
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        events.push_back(event);
    }
}
