#ifndef HITBOX_H
#define HITBOX_H
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
      void setOnEnter(std::function<void(Hitbox*)>);
      void setOnExit(std::function<void(Hitbox*)>);
      void update(SDL_Renderer *renderer);
    private:
      static std::vector<Hitbox*> allHitboxes;
      std::vector<Hitbox*> collidingHitboxes;
      std::string tag;
      std::function<void(Hitbox*)> onEnterFunction;
      std::function<void(Hitbox*)> onExitFunction;

      SDL_FRect hitbox;
  };
}

#endif
