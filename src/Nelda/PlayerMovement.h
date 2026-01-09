#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../GameEngine/InputManager.h"

namespace GE {

/*
  ? Ev ska Movement ingå i Player ist - mer ett beeteende?
*/
class Movement {
public:
    
    explicit Movement(float speed);

    // Uppdaterar positionen (anropas från Player::update) - man vill kunna ändra speed
    void update(float& x, float& y);

    
    void setSpeed(float newSpeed);

private:
    float speed {0.0f};
};

} 

#endif
