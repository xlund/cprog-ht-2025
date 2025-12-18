#include "Player.h"

namespace GE {

Player::Player()
    : movement(2.5f) //! spelarens rörelsehastighet - vad är rimligt?
{
}

/*
  setup körs en gång. Tänker att här skapas sprite och hitbox samt startposition.
*/
void Player::setup() {

    //! Startposition - vad är egentligen rimligt
    x = 100.0f;
    y = 100.0f;

    //! Hur borde Sprite se ut här?
    sprite = new Sprite(
        static_cast<int>(x), static_cast<int>(y), 0,0, "assets/player.png", nullptr             
        //! renderer sätts av engine senare?
    );


    hitbox = new Hitbox(
        x, y,
        50.0f, 
        50.0f        //! bredd och höjd - vad borde vi ha här?
    );

    hitbox->setTag("Player");
}


void Player::update() {

    //updatering
    movement.update(x, y);

    // Synka sprite med positionrna
    if (sprite) {
        sprite->setX(static_cast<int>(x));
        sprite->setY(static_cast<int>(y));
    }

    // Synka hitbox med positionerna
    if (hitbox) {
        hitbox->setPosition(x, y);
    }
}

} 
