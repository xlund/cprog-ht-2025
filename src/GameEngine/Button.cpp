#include "Button.h"
#include "Text.h"
#include "Hitbox.h"
#include"InputManager.h"


GE::Button::Button(std::string text, int x,int y,int w,int h) : 
GE::Component(x,y,0),
text(text,x,y), 
hitbox(x,y,w,h){
    
}

void GE::Button::update(){
    text.draw();
    float mx,my;
    GE::InputManager::getMousePosition(mx,my);
    
}