#include "LevelChanger.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"
#include <iostream>

LevelChanger::LevelChanger(float w, float h, const LevelCreator &lc) : levelCreator(lc){
    hitbox = new GE::Hitbox(0,0,w,h);
}

LevelChanger* LevelChanger::create(float w, float h, const LevelCreator& lc ){
    return new LevelChanger(w,h,lc);
}

void LevelChanger::setup(GE::GameEngine * ge){
    ge->addComponent(hitbox);
    gameEngin = ge;
    hitbox->setOnEnter([&ge,this](GE::Hitbox*){

        this->levelCreator.make(*ge);
    });
}

void LevelChanger::update(){
    hitbox->setPosition(x,y);
}