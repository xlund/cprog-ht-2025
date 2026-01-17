#include "WallDetection.h"
#include "../GameEngine/Hitbox.h"
#include <string>

void wallDetection(GE::Hitbox& hitbox,  float& x,float& y){
    while(hitbox.isTuching("WallUp")){
        y=y-0.1;
        hitbox.setPosition(x,y);
    }
    while(hitbox.isTuching("WallDown")){
        y=y+0.1;
        hitbox.setPosition(x,y);
    }
    while(hitbox.isTuching("WallLeft")){
        x=x-0.1;
        hitbox.setPosition(x,y);
    }
    while(hitbox.isTuching("WallRight")){
        x=x+0.1;
        hitbox.setPosition(x,y);
    }
}