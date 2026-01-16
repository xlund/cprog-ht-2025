#ifndef BUTTON_H
#define BUTTON_H

#include "Text.h"
#include "Hitbox.h"
#include <functional>
#include "Component.h"
#include <string>
namespace GE {
  class Button : public Text{
    public:
      Button* create(std::string,int,int,int,int);
      void setOnClick(std::function<void()>);
      void update();
    private:
    Button(std::string,int,int,int,int);
    Button(const Button&)=delete;
    Button& operator=(const Button&)=delete;
      GE::Hitbox* hitbox;
      std::function<void()> onClick;

  };
}

#endif
