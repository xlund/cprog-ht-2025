 #include "Goal.h"

namespace GE {

Goal::Goal() {
}

void Goal::setup(GE::GameEngine* ge) {

    // placera triforce i världen
    x = 400.0f;
    y = 300.0f;

    // Skapa hitbox (syns ej, men används för kollision)
    hitbox = new Hitbox(
        x,
        y,
        40.0f,
        40.0f
    );

    hitbox->setTag("Goal");
}

void Goal::update() {

    if (collected) {
        return; //! inget mer att göra?
    }

    // !Här kan vi kanske senare lägga animation / glow / ljud??
}

bool Goal::isCollected() const {
    return collected;
}

}
