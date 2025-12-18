#ifndef PLAYER_H
#define PLAYER_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Sprite.h"
#include "../GameEngine/Hitbox.h"
#include "Movement.h"

namespace GE {

/*
  Player ett GameObject.
  Den samlar ihop logik (Movement),
  rendering (Sprite) och kollision (Hitbox).
*/
class Player : public GameObject {
public:
    Player();

   
    void setup() override;

 
    void update() override;

private:
    // Positionenrna  
    float x {0.0f};
    float y {0.0f};

    // Rörelselogik - osäker här?
    Movement movement;

    // komponenter kopplade till spelare
    Sprite* sprite {nullptr};
    Hitbox* hitbox {nullptr};
};

} 

#endif
