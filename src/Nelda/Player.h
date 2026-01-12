#ifndef PLAYER_H
#define PLAYER_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Sprite.h"
#include "../GameEngine/Hitbox.h"
#include "PlayerMovement.h"

namespace GE {

class GameEngine;

class Player : public GameObject {
public:
    static Player* create();

    void setup(GameEngine* engine) override;
    void update() override;

private:
    Player();

    Movement movement;
    Sprite* sprite{nullptr};
    Hitbox* hitbox{nullptr};
};

} // namespace GE

#endif
