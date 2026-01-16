#ifndef BUTTON_H
#define BUTTON_H

#include "Text.h"
#include "Hitbox.h"
#include <functional>
#include "Component.h"
#include <string>
#include "GameEngine.h"
namespace GE {
  class Button : public Text{
    public:
      ~Button();

      Button* create(std::string,int,int,int,int,GE::GameEngine*);
      void setOnClick(std::function<void()>);
      void update();
    private:
    Button(std::string,int,int,int,int,GE::GameEngine*);
    Button(const Button&)=delete;
    Button& operator=(const Button&)=delete;
      GE::Hitbox* hitbox;
      std::function<void()> onClick;

  };
}

#endif
