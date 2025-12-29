#include "Enemy.h"
#include "TempObject.h"
#include "../GameEngine/Sprite.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/InputManager.h"
#include <iostream>
#include "WallDetection.h"
#include "../GameEngine/InputManager.h"

Enemy::Enemy(TempObject target,int x, int y, int speed) : target(target), x(x),y(y),speed(speed){}

void Enemy::setup(GE::GameEngine* engine){
    hitbox = new GE::Hitbox(x,y,100,100);   
    engine->addComponent(hitbox); 
    hitbox->setOnEnter([this](GE::Hitbox* other){
        //wallDetection(other);
    });
    speed = 1;
}

void Enemy::update(){

    /*target.getPos(targetX,targetY);
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
    }*/
   
    if(GE::InputManager::isKeyDown("w")){
      y-=speed;  
    }
    if(GE::InputManager::isKeyDown("s")){
       y+=speed; 
    }
    if(GE::InputManager::isKeyDown("a")){
      x-=speed;  
    }
    if(GE::InputManager::isKeyDown("d")){
        x+=speed;
    }

    wallDetection(hitbox,"Wall",x,y);

    hitbox->setPosition(x,y);
}

