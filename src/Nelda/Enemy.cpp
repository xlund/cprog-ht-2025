#include "Enemy.h"
#include "TempObject.h"
#include "../GameEngine/Sprite.h"
#include "../GameEngine/GameEngine.h"

Enemy::Enemy(TempObject target) : target(target){}

void Enemy::setup(GE::GameEngine* engine){

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