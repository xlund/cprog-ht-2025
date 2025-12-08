#include <string>
#include "Text.h"
#include"../include/Constants.h"

GE::Text::Text(std::string text) : str(text),
    font(TTF_OpenFont(constants::STANDARD_FONT.c_str(),24)),
    fontPath(constants::STANDARD_FONT),
    size(24){}

GE::Text::Text(std::string text,std::string path,int size):str(text),
    font(TTF_OpenFont(path.c_str(),size)),
    fontPath(path),
    size(size){}

void GE::Text::setString(const std::string &text){
    this->str = text;
}

std::string GE::Text::getString() const{
    return this->str;
}

void GE::Text::setFont(const std::string &path){
    font = TTF_OpenFont(path.c_str(),size);
}

void GE::Text::setSize(const int &size){
    font = TTF_OpenFont(fontPath.c_str(),size);
}
      void draw();
      void hide();
      void erase();