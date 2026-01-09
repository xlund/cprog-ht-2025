#include "TempObject.h"
TempObject::TempObject(int x, int y) : GameObject(x,y){}

void TempObject::getPos(int& x,int& y) const{
    x = this->x;
    y= this->y;
}

void TempObject::setPos(const int x, const int y){
    this->x = x;
    this->y = y;
}