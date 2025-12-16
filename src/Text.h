#ifndef TEXT_H
#define TEXT_H

#include "Component.h"
#include <string>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL.h>
namespace GE {
  class Text : public GE::Component {
    public:
    Text(std::string,int,int);
    Text(std::string,std::string,int,int,int);
    ~Text();
      void setString(const std::string &);
      std::string getString() const;
      void setColor(unsigned char ,unsigned char, unsigned char, unsigned char);
      void setFont(const std::string &);
      void setFontSize(int);
      void draw();
      void hide();
      void erase();
      void update(SDL_Renderer*);
    
      private:
      std::string str{""};
      TTF_Font* font{};
      std::string fontPath{""};
      int fontSize{0};
      SDL_Color color{0,0,0,0};
      bool isSeen{false};

      int width;
      int height;
  };
}



#endif