#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../GameEngine/InputManager.h"

namespace GE {

/*

  !Den ansvarar för rörelse baserat på input, visst ska inte Movement äga en position själv?
*/
class Movement {
public:
    //!Tänker att denna klass inte får användas för automatiska (implicita) typomvandlingar?
    explicit Movement(float speed);

    // Uppdaterar positionen (anropas från Player::update)
    void update(float& x, float& y);

    //! Ändrar hastigheten - räcker kanske med update?
    void setSpeed(float newSpeed);

private:
    float speed {0.0f};
};

} // namespace GE

#endif
