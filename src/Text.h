#ifndef TEXT_H
#define TEXT_H

#include "ScreenComponent.h"
#include <string>
#include <SDL3_ttf/SDL_ttf.h>
namespace GE {
  class Text : public ScreenComponent {
    public:
    Text(std::string);
    Text(std::string,std::string,int);
      void setString(std::string);
      std::string getString();
      void draw();
      void hide();
      void erase();
    private:
      TTF_Font* font;
      std::string str{""};
  };
}



#endif
