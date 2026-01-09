#ifndef PLAYER_H
#define PLAYER_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Sprite.h"
#include "../GameEngine/Hitbox.h"
#include "PlayerMovement.h"
#include "../GameEngine/GameEngine.h"

namespace GE {

/*
  Player ett GameObject.
  Den samlar ihop logik (Movement),
  rendering (Sprite) och kollision (Hitbox).
*/
class Player : public GameObject {
public:
    static Player* create();

    void setup(GameEngine*) override;

 
    void update() override;

private:
    Player();
    // Positionenrna  


    // Rörelselogik - osäker här?
    Movement movement;

    // komponenter kopplade till spelare
    Sprite* sprite {nullptr};
    Hitbox* hitbox {nullptr};
};

} 

#endif
