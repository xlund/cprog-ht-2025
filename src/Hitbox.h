#ifndef HITBOX_H
#define HITBOX_H

#include "ScreenComponent.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <functional>
#include <vector>
#include <string>
namespace GE {
  class Hitbox: public Component {
    public:
      Hitbox(float,float,float,float);
      ~Hitbox();
      std::string getTag() const;
      void setTag(const std::string&);
      void getPosition(float&, float&) const;
      void setPosition(const float ,const float);
      void getDimentions(float&, float&) const;
      void setDimentions(const float, const float);
      Sprite onEnter(std::function<void()>);
      Sprite onExit(std::function<void()>);
      void update(SDL_Renderer *renderer);
    private:
      static std::vector<Hitbox*> allHitboxes;
      std::string tag;
      std::function<void()> func;
      SDL_FRect hitbox;
  };
}

#endif
