#include "Button.h"
#include "Text.h"
#include "Hitbox.h"
#include "InputManager.h"
#include <functional>
#include <stdexcept>


GE::Button::Button(std::string text, int x,int y,int w,int h) : 
GE::Component(x,y,0),
text(text,x,y), 
hitbox(x,y,w,h){
}

void GE::Button::setOnClick(std::function<void()> func){
    onClick = func;
}


void GE::Button::update(){
    this->text.draw();
    this->text.setColor(255,255,255,255);
    text.update();

    bool isClicked = hitbox.isClicked();
    if(isClicked && onClick){
        onClick();
    }
    else if(isClicked && !onClick){
        throw std::invalid_argument("Ingen metod definierad");
    }    
}