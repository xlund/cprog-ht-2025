#ifndef TEXT_H
#define TEXT_H

#include "ScreenComponent.h"
#include <string>
#include <SDL3_ttf/SDL_ttf.h>
namespace GE {
  class Text : public ScreenComponent {
    public:
    Text(std::string,int,int);
    Text(std::string,std::string,int,int,int);
      void setString(const std::string &);
      std::string getString() const;
      void setColor(unsigned char ,unsigned char, unsigned char, unsigned char);
      void setFont(const std::string &);
      void setSize(int);
      void draw();
      void hide();
      void erase();
    
      private:
      std::string str{""};
      TTF_Font* font;
      std::string fontPath;
      int size;
      SDL_Color color{0,0,0,0};
  };
}



#endif
