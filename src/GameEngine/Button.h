#ifndef BUTTON_H
#define BUTTON_H

#include "Text.h"
#include "Hitbox.h"
#include <functional>
#include "Component.h"
#include <string>
namespace GE {
  class Button : public GE::Component{
    public:
      Button(std::string,int,int,int,int);
      void onClick(std::function<void()>);
      void update();
    private:
      GE::Text text;
      GE::Hitbox hitbox;
  };
}

#endif
