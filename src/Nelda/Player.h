#ifndef PLAYER_H
#define PLAYER_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Sprite.h"
#include "../GameEngine/Hitbox.h"

namespace GE {

class GameEngine;

class Player : public GameObject {
public:
    static Player* create();

    void setup(GameEngine* engine) override;
    void update() override;

private:
    Player();

    void handleMovement();

    float speed {3.0f};

    Sprite* sprite {nullptr};
    Hitbox* hitbox {nullptr};

    int spriteWidth  {0};
    int spriteHeight {0};
};

} // namespace GE

#endif // PLAYER_H
