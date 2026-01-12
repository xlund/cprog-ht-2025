#include "Player.h"
#include "../GameEngine/GameEngine.h"

namespace GE {

Player* Player::create() {
    return new Player();
}

Player::Player()
    : movement(2.5f) // rörelsehastighet
{
}

void Player::setup(GameEngine* ge /*engine*/) {

    // Startposition
    x = 100.0f;
    y = 100.0f;

    // Skapa sprite
    sprite = new Sprite(
        static_cast<int>(x),
        static_cast<int>(y),
        0,  // z-layer
        0,  
        constants::player_sprite
    );

  
    hitbox = new Hitbox(
        x,
        y,
        64.0f,
        32.0f
    );

    hitbox->setTag("Player");
    ge->addComponent(sprite);
    ge->addComponent(hitbox);
}

void Player::update() {

    sprite ->draw();

    // Uppdatera rörelse
    movement.update(x, y);

   
    if (sprite) {
        sprite->setX(static_cast<int>(x));
        sprite->setY(static_cast<int>(y));
    }

    // Synka hitbox
    if (hitbox) {
        hitbox->setPosition(x, y);
    }
}

} // namespace GE
