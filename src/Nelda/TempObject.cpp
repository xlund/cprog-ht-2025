#include "TempObject.h"

void TempObject::getPos(int& x,int& y) const{
    x = this->x;
    y= this->y;
}

void TempObject::setPos(const int x, const int y){
    this->x = x;
    this->y = y;
}