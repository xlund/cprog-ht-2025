#include "Component.h"

GE::Component::Component(){};
GE::Component::Component(int x,int y, int r) : x(x),y(y),rotation(r){};
int GE::Component::getX()const{
    return x;
}

int GE::Component::getY()const{
    return y;
}

int GE::Component::getRotation()const{
    return rotation;
}

void GE::Component::setX(const int x){
    this -> x = x;
}

void GE::Component::setY(const int y){
    this -> y = y;
}

void GE::Component::setRotation(const int rotation){
    this -> rotation = rotation;
}