#include <string>
#include "Text.h"
#include"../include/Constants.h"
#include "ScreenComponent.h"
#include <stdexcept>
#include "GameEngine.h"
#include <iostream>


GE::Text::Text(SDL_Renderer* ren ,std::string text, int x, int y) : 
    ScreenComponent(x,y,0,0,0),
    renderer(ren),
    str(text),
    font(TTF_OpenFont(constants::STANDARD_FONT.c_str(),24)),
    fontPath(constants::STANDARD_FONT),
    size(24){}

GE::Text::Text(SDL_Renderer* ren, std::string text,std::string path,int size,int x,int y):
    ScreenComponent(x,y,0,0,0),
    renderer(ren),
    str(text),
    font(TTF_OpenFont(path.c_str(),size)),
    fontPath(path),
    size(size){}

GE::Text::~Text() {
    if(font){
        TTF_CloseFont(font);
    }
}

void GE::Text::setString(const std::string &text){
    this->str = text;
}

void GE::Text::erase(){
    str="";
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

void GE::Text::draw(){
    isSeen=true;
}

void GE::Text::update(){

    if(str.empty()){return;}
    if(!font){throw std::invalid_argument("Font dose not exist");}
    if(isSeen){
    SDL_Surface* surface = TTF_RenderText_Solid(font,str.c_str(),0,color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_DestroySurface(surface);
    SDL_FRect rect = {static_cast<float>(x),static_cast<float>(y),static_cast<float>(texture->w),static_cast<float>(texture->h)};
    SDL_RenderTexture(renderer,texture,NULL,&rect);
    SDL_DestroyTexture(texture);
    }
}
void GE::Text::hide(){
    isSeen=false;
}
