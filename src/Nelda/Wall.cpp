#include "Wall.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/GameObject.h"
#include "../GameEngine/Sprite.h"



Wall::Wall(float x,float y,float length) : length(length){}

Wall* Wall::create(float x,float y,float length){
    return new Wall(x,y,length);
}

Wall::~Wall(){
    for(GE::Hitbox* h : hitboxes){
        delete h;
    }
    delete sprite;
}


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

    GE::Hitbox* u = GE::Hitbox::create(x+(length*barThickness),y,length*barProcentage,(length*barThickness),engin);
    u->setTag("WallUp");
    GE::Hitbox* r = GE::Hitbox::create(x+length-(length*barThickness),y+(length*barThickness),(length*barThickness),length*barProcentage,engin);
    r->setTag("WallRight");
    GE::Hitbox* d = GE::Hitbox::create(x+(length*barThickness),y+length-(length*barThickness),length*barProcentage,(length*barThickness),engin);
    d->setTag("WallDown");
    GE::Hitbox* l = GE::Hitbox::create(x,y+(length*barThickness),(length*barThickness),length*barProcentage, engin);
    l->setTag("WallLeft");

    hitboxes.push_back(u);
    hitboxes.push_back(r);
    hitboxes.push_back(d);
    hitboxes.push_back(l);


    sprite = GE::Sprite::create(x,y,0,0,constants::wall_image,engin);
    
}
void Wall::update(){
    sprite->draw();
}