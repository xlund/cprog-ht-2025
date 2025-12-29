#include "Wall.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameObject.h"


Wall::Wall(float x,float y,float length) : x(x), y(y),length(length){}

void Wall::setup(GE::GameEngine* engin){
    /*GE::Hitbox* d = new GE::Hitbox(x+(length/2),y,length/10,length);
    GE::Hitbox* u = new GE::Hitbox(x-(length/2),y,length/10,length);
    GE::Hitbox* l = new GE::Hitbox(x,y-(length/2),length,length/10);
    GE::Hitbox* r = new GE::Hitbox(x,y+(length/2),length,length/10);
    
    hitboxes.push_back(d);
    hitboxes.push_back(u);
    hitboxes.push_back(l);
    hitboxes.push_back(r);
    */
    float barProcentage = 0.85;
    float barThickness = (1-barProcentage)/2;

    GE::Hitbox* u = new GE::Hitbox(x+(length*barThickness),y,length*barProcentage,(length*barThickness));
    GE::Hitbox* r = new GE::Hitbox(x+length,y+(length*barThickness),-(length*barThickness),length*barProcentage);
    GE::Hitbox* d = new GE::Hitbox(x+(length*barThickness),y+length,length*barProcentage,-(length*barThickness));
    GE::Hitbox* l = new GE::Hitbox(x,y+(length*barThickness),(length*barThickness),length*barProcentage);

    hitboxes.push_back(d);
    hitboxes.push_back(u);
    hitboxes.push_back(l);
    hitboxes.push_back(r);


    
    for(GE::Hitbox* h : hitboxes){
        engin->addComponent(h);
    }
    //hitbox = new GE::Hitbox(x,y,1000,100);
    //hitbox->setTag("Wall");
    //engin->addComponent(hitbox);
}
void Wall::update(){

}