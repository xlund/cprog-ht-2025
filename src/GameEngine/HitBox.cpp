#include "Hitbox.h"
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include "InputManager.h"
#include "GameEngine.h"


std::vector<GE::Hitbox*> GE::Hitbox::allHitboxes;

GE::Hitbox* GE::Hitbox::create(float x, float y, float width, float height,GE::GameEngine* ge){
    return new Hitbox(x,y,width,height,ge);
}

GE::Hitbox::Hitbox(float x, float y, float width, float height,GE::GameEngine* ge): Component(ge){
    hitbox={x,y,width,height};
    allHitboxes.push_back(this);
}

GE::Hitbox::~Hitbox(){
    auto i = std::find(allHitboxes.begin(), allHitboxes.end(), this);
    allHitboxes.erase(i);
}

std::string GE::Hitbox::getTag() const {
    return tag;
}

void GE::Hitbox::setTag(const std::string& newTag){
    tag = newTag;
}


void GE::Hitbox::getPosition(float& x, float& y) const{
    x = hitbox.x;
    y = hitbox.y;
}

void GE::Hitbox::setPosition(const float x,const float y){
    hitbox.x = x;
    hitbox.y = y;
}

void GE::Hitbox::getDimentions(float& width, float& height) const{
    width = hitbox.w;
    height = hitbox.h;
}

void GE::Hitbox::setDimentions(const float width, const float height){
    hitbox.w = width;
    hitbox.h = height;
}

void GE::Hitbox::setOnEnter(const std::function<void(Hitbox*)>& function){
    onEnterFunction = function;
}

void GE::Hitbox::setOnExit(const std::function<void(Hitbox*)>& function){
    onExitFunction = function;
}

void GE::Hitbox::update(){
    for(Hitbox* other : allHitboxes){
        bool hasCollided=(std::find(collidingHitboxes.begin(),collidingHitboxes.end(),other) != collidingHitboxes.end());
        bool touching = isTuching(other);

        if(other != this && touching && !hasCollided){
            if(onEnterFunction){
                onEnterFunction(other);
            }
            collidingHitboxes.push_back(other);
        }
        else if(!touching && hasCollided){
            if(onExitFunction){
                onExitFunction(other);
            }
            auto i = std::find(collidingHitboxes.begin(), collidingHitboxes.end(), other);
            collidingHitboxes.erase(i);
        }
    }

    if(GE::InputManager::isKeyPressed("h")){
        debug = !debug;
    }
    SDL_Renderer *renderer = GE::GameEngine::getRenderer();
    if(debug &&  renderer!= nullptr){
        SDL_SetRenderDrawColor(renderer, 255,0,0,255);
        SDL_RenderFillRect(renderer,&hitbox);
    }
}

bool GE::Hitbox::isTuching(GE::Hitbox* other){
    return SDL_HasRectIntersectionFloat(&hitbox,&other->hitbox);
}

bool GE::Hitbox::isTuching(std::string tag){
    bool tuching = false; 
    for(Hitbox* other : allHitboxes){
        if(other != this && other->getTag()==tag && tuching == false){
            tuching = SDL_HasRectIntersectionFloat(&hitbox,&other->hitbox);
        }
    }
    return tuching;
}

bool GE::Hitbox::isClicked(){
    float mx, my;
    GE::InputManager::getMousePosition(mx,my);

        bool mouseHovering =
        mx >= hitbox.x &&
        mx <= hitbox.x + hitbox.w &&
        my >= hitbox.y &&
        my <= hitbox.y + hitbox.h;

        if(!mouseHovering){
            return false;
        }

        return GE::InputManager::isLeftMousePressed();
}