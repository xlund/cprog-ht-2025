#include <string>
#include "Text.h"
#include"../include/Constants.h"
#include "ScreenComponent.h"
#include <stdexcept>

GE::Text::Text(std::string text, int x, int y) : str(text),
    font(TTF_OpenFont(constants::STANDARD_FONT.c_str(),24)),
    fontPath(constants::STANDARD_FONT),
    size(24),
    ScreenComponent(x,y,0,0,0){}

GE::Text::Text(std::string text,std::string path,int size,int x,int y):str(text),
    font(TTF_OpenFont(path.c_str(),size)),
    fontPath(path),
    size(size),
    ScreenComponent(x,y,0,0,0){}

void GE::Text::setString(const std::string &text){
    this->str = text;
}

std::string GE::Text::getString() const{
    return this->str;
}

void GE::Text::setColor(unsigned char r, unsigned char g ,unsigned char b,unsigned char brightnes){
    color = {r,g,b,brightnes};
}

void GE::Text::setFont(const std::string &path){
    font = TTF_OpenFont(path.c_str(),size);
}

void GE::Text::setSize(int size){
    font = TTF_OpenFont(fontPath.c_str(),size);
}
      void draw();
      void hide();
      void erase();