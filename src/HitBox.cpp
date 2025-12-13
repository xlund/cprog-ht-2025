#include "Hitbox.h"
#include <algorithm>
#include <vector>
#include <string>

std::vector<GE::Hitbox*> GE::Hitbox::allHitboxes;


GE::Hitbox::Hitbox(float x, float y, float width, float height){
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

void GE::Hitbox::setOnEnter(std::function<void()> function){
    onEnterFunction = function;
}

void GE::Hitbox::setOnExit(std::function<void()> function){
    onExitFunction = function;
}

void GE::Hitbox::update(SDL_Renderer* renderer){
    for(Hitbox* other : allHitboxes){
        if(other != this && SDL_HasRectIntersectionFloat(&hitbox,&other->hitbox)){
            onEnterFunction;
            collidingHitboxes.push_back(other);
        }
        else{
            onEnterFunction;
            auto i = std::find(collidingHitboxes.begin(), collidingHitboxes.end(), other);
            collidingHitboxes.erase(i);
        }
    }
}