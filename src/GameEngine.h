#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Sprite.h"

namespace GameEngine {
   class GameEngine {
     public:
       void tick();
       void setFps();
       int getFps();
       bool spawnEntity(Sprite);
     private: 
       int fps{60};
   };
};

#endif



