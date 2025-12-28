#include "Wall.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameObject.h"


Wall::Wall(int x,int y) : x(x), y(y){}

void Wall::setup(GE::GameEngine* engin){
    hitbox = new GE::Hitbox(x,y,1000,100);
    hitbox->setTag("Wall");
    engin->addComponent(hitbox);
}
void Wall::update(){

}