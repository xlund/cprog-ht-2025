#include "WallDetection.h"
#include "../GameEngine/Hitbox.h"
#include <string>

void wallDetection(GE::Hitbox* hitbox, const std::string& tag, float& x,float& y){
        while(hitbox->isTuching("Wall")){
        y=y-0.1;
        hitbox->setPosition(x,y);
    }
}