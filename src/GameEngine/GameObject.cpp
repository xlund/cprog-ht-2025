#include "GameObject.h"

GE::GameObject::GameObject(GameEngine* ge, float x,float y) : gameEngine(ge), x(x), y(y){}
GE::GameObject::GameObject(GameEngine* ge) : x(0), y(0),gameEngine(ge){}

void GE::GameObject::setPos(float x, float y){
    this->x = x;
    this->y = y;
}

void GE::GameObject::getPos(float &x, float &y){
    x = this->x;
    y = this->y;
}