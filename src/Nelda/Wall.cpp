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
    GE::Hitbox* u = new GE::Hitbox(x+(length*0.1),y,length*0.8,-(length/20));
    GE::Hitbox* l = new GE::Hitbox(x+length,y+(length*0.1),length/20,length*0.8);
    GE::Hitbox* d = new GE::Hitbox(x+(length*0.1),y+length,length*0.8,(length/20));
    GE::Hitbox* r = new GE::Hitbox(x,y+(length*0.1),-(length/20),length*0.8);

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