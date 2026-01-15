#include "Button.h"
#include "Text.h"
#include "Hitbox.h"
#include "InputManager.h"
#include <functional>
#include <stdexcept>


GE::Button* GE::Button::create(std::string text, int x,int y,int w,int h){
    return new Button(text,x,y,w,h);
}

GE::Button::Button(std::string text, int x,int y,int w,int h) : 
Text(text,x,y),
hitbox(x,y,w,h){
}

void GE::Button::setOnClick(std::function<void()> func){
    onClick = func;
}


void GE::Button::update(){
    draw();
    setColor(255,255,255,255);
    Text::update();

    bool isClicked = hitbox.isClicked();
    if(isClicked && onClick){
        onClick();
    }
    else if(isClicked && !onClick){
        throw std::invalid_argument("Ingen metod definierad");
    }    
}