#include "Enemy.h"
#include "TempObject.h"
#include "../GameEngine/Sprite.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/InputManager.h"
#include <iostream>

Enemy::Enemy(TempObject target,int x, int y) : target(target), x(x),y(y){}

void Enemy::setup(GE::GameEngine* engine){
    hitbox = new GE::Hitbox(x,y,100,100);   
    engine->addComponent(hitbox); 

    speed = 1;
}

void Enemy::update(){

    target.getPos(targetX,targetY);
    if(targetX<x){
        x-=speed;
    }
    if(targetX>x){
        x+=speed;
    }
    if(targetY<y){
        y-=speed;
    }
    if(targetY>y){
        y+=speed;
    }


    hitbox->setPosition(x,y);
}