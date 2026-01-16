#ifndef HITBOX_H
#define HITBOX_H
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <functional>
#include <vector>
#include <string>
#include "GameEngine.h"
namespace GE {
  class Hitbox: public Component {
    public:
      static Hitbox* create(float,float,float,float,GE::GameEngine*);
      ~Hitbox();
      std::string getTag() const;
      void setTag(const std::string&);
      void getPosition(float&, float&) const;
      void setPosition(const float ,const float);
      void getDimentions(float&, float&) const;
      void setDimentions(const float, const float);
      void setOnEnter(const std::function<void(Hitbox*)> &);
      void setOnExit(const std::function<void(Hitbox*)> &);
      void update();
      bool isTuching(Hitbox*);
      bool isTuching(std::string);
      bool isClicked();
    private:
      Hitbox(float,float,float,float,GE::GameEngine*);
      Hitbox(const Hitbox&)=delete;
      Hitbox& operator=(const Hitbox&)=delete;;
      static std::vector<Hitbox*> allHitboxes;
      std::vector<Hitbox*> collidingHitboxes;
      std::string tag;
      std::function<void(Hitbox*)> onEnterFunction;
      std::function<void(Hitbox*)> onExitFunction;

      SDL_FRect hitbox;
      bool debug{false};
  };
}

#endif
