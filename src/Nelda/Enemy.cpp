#include "Enemy.h"
#include "TempObject.h"
#include "../GameEngine/Sprite.h"

Enemy::Enemy(TempObject target) : target(target){}

void Enemy::setup(){
    
}

void Enemy::update(){
    target.getPos(targetX,targetY);

    if(targetX<x){
        x-=speed;
    }
    else{
        x+=speed;
    }
    if(targetY<y){
        y-=speed;
    }
    else{
        y+=speed;
    }
}