#ifndef PLAYER_H
#define PLAYER_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/Sprite.h"
#include "Game.h"
#include "Health.h"

class Player : public GE::GameObject {
public:
    static Player* create(GameState&);

    ~Player();

    void setup(GE::GameEngine* engine) override;
    void update() override;

private:
    Player(GameState&);

    GameState& gameState_;

    Health hp;
    float speed{3.0f};

    GE::Sprite* sprite{nullptr};
    int spriteWidth{0};
    int spriteHeight{0};

    GE::Hitbox* hitbox{nullptr};
};

#endif
