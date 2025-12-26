#include "Enemy.h"
#include "TempObject.h"
#include "../GameEngine/Sprite.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"

Enemy::Enemy(TempObject target) : target(target){}

void Enemy::setup(GE::GameEngine* engine){
    GE::Hitbox* hitbox = new GE::Hitbox(10,10,100,100);   
    engine->addComponent(hitbox); 
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