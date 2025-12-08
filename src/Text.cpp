#include <string>
#include "Text.h"
#include"../include/Constants.h"

GE::Text::Text(std::string text) : str(text),
    font(TTF_OpenFont(constants::STANDARD_FONT.c_str(),24)){}

GE::Text::Text(std::string text,std::string path,int size):str(text),
    font(TTF_OpenFont(path.c_str(),size)){}

