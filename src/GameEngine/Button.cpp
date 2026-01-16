#include "Button.h"
#include "Text.h"
#include "Hitbox.h"
#include "InputManager.h"
#include <functional>
#include <stdexcept>


GE::Button* GE::Button::create(std::string text, int x,int y,int w,int h,GE::GameEngine* ge){
    GE::Button* b = new Button(text,x,y,w,h,ge);
    ge->addComponent(b);
    return b;
}

GE::Button::Button(std::string text, int x,int y,int w,int h, GE::GameEngine* ge) : 
Text(text,x,y,ge){
    hitbox = Hitbox::create(x,y,w,h,ge);
}

GE::Button::~Button(){
    gameEngine->removeComponent(this);
}

void GE::Button::setOnClick(std::function<void()> func){
    onClick = func;
}


void GE::Button::update(){
    draw();
    setColor(255,255,255,255);
    Text::update();

    bool isClicked = hitbox->isClicked();
    if(isClicked && onClick){
        onClick();
    }
    else if(isClicked && !onClick){
        throw std::invalid_argument("Ingen metod definierad");
    }    
}