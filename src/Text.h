#ifndef TEXT_H
#define TEXT_H

#include "ScreenComponent.h"
#include <string>
namespace GameEngine {
  class Text : public ScreenComponent {
    public:
      void setString(std::string);
      std::string getString();
      void draw();
      void hide();
      void erase();
    private:
      std::string str{""};
  };
}



#endif
