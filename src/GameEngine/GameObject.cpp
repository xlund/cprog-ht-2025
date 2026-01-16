#include "GameObject.h"

GE::GameObject::GameObject(GameEngine* ge, float x,float y) : gameEngine(ge), x(x), y(y){}
GE::GameObject::GameObject(GameEngine* ge) :gameEngine(ge), x(0), y(0){}

void GE::GameObject::setPos(float x, float y){
    this->x = x;
    this->y = y;
}

void GE::GameObject::getPos(float &x, float &y){
    x = this->x;
    y = this->y;
}

bool GE::GameObject::isDeleteable(){
    return deleteable;
}

void GE::GameObject::setToDelete(){
    deleteable = true;
}