#include "InputManager.h"
#include <SDL3/SDL.h>
#include <vector>
#include <string>
#include <stdexcept>


std::vector<SDL_Event> events;
const bool* keyStates;
unsigned int mouseStates;
float mouseX, mouseY;

bool GE::IM::isKeyDown(std::string key) {
    SDL_Scancode code = SDL_GetScancodeFromName(key.c_str());
    return keyStates[code];
}

bool isKeyInteracted(std::string key,SDL_EventType type){
        for(SDL_Event event : events){
            SDL_Keycode code = SDL_GetKeyFromName(key.c_str());
        if(event.type==type && event.key.key == code){
            return true;
        }
    }
    return false;
}

bool isMouseInteracted(int button,SDL_EventType type){
        for(SDL_Event event : events){
        if(event.type==type && event.button.button == button){
            return true;
        }
    }
    return false;
}


bool GE::IM::isKeyPressed(std::string key){
    return isKeyInteracted(key,SDL_EVENT_KEY_DOWN);
}

bool GE::IM::isKeyReleased(std::string key){
    return isKeyInteracted(key,SDL_EVENT_KEY_UP);
}

bool GE::IM::isLeftMousePressed(){
    return isMouseInteracted(SDL_BUTTON_LEFT,SDL_EVENT_MOUSE_BUTTON_DOWN);
}

bool GE::IM::isRightMousePressed(){
    return isMouseInteracted(SDL_BUTTON_RIGHT,SDL_EVENT_MOUSE_BUTTON_DOWN);
}

bool GE::IM::isLeftMouseReleased(){
    return isMouseInteracted(SDL_BUTTON_LEFT,SDL_EVENT_MOUSE_BUTTON_UP);
}

bool GE::IM::isRightMouseReleased(){
    return isMouseInteracted(SDL_BUTTON_RIGHT,SDL_EVENT_MOUSE_BUTTON_UP);
}

bool GE::IM::isLeftMouseDown(){
    return mouseStates & SDL_BUTTON_LMASK;
}

bool GE::IM::isRightMouseDown(){
    return mouseStates & SDL_BUTTON_RMASK;
}

void GE::IM::getMousePosition(float &x, float &y){
    x = mouseX;
    y = mouseY;
}

void GE::IM::fetchKeys(){
    events.clear();
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        events.push_back(event);
    }

    keyStates = SDL_GetKeyboardState(NULL);
    mouseStates = SDL_GetMouseState(&mouseX, &mouseY);
}