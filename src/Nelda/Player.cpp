#include "Player.h"
#include "../GameEngine/GameEngine.h"
#include "Constants.h"

namespace GE {

Player* Player::create() {
    return new Player();
}

Player::Player()
    : movement(2.5f)
{
}

void Player::setup(GameEngine* engine) {

    // Startposition (kan även sättas via level)
    x = 0;
    y = 0;

    // Hitbox (matcha gärna sprite)
    hitbox = new Hitbox(x, y, 32, 54);
    hitbox->setTag("Player");

  
    sprite = new Sprite(
        x,
        y,
        0,
        0,
        constants::player_sprite
    );

    // Registrera ENDAST hitbox i engine
    engine->addComponent(hitbox);
    engine->addComponent(sprite);
}

void Player::update() {

    // Rörelse
    movement.update(x, y);

    // Synka hitbox
    hitbox->setPosition(x, y);

    // Synka sprite
    sprite->setX(x);
    sprite->setY(y);

    //  rita sprite själv
    sprite->draw();
}

} // namespace GE
