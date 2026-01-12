#include "Constants.h"
#include "GameEngine/GameEngine.h"
#include "Nelda/LevelCreator.h"
#include "Nelda/Player.h"
#include "Nelda/Enemy.h"
#include "Nelda/Wall.h"

int main(int argc, char* argv[]) {

    GE::GameEngine game("Nelda");

    LevelCreator lc("./src/Nelda/level.txt", 100);

    // PLAYER
    lc.setGameObject('p', []() {
        return GE::Player::create();
    });

    // Väggar
    lc.setGameObject('w', []() {
        return Wall::create(200, 200, 100);
    });

    // Fiender
    lc.setGameObject('e', []() {
        return Enemy::create(TempObject(400, 500), 10, 10, 1);
    });

    // Skapa alla objekt
    lc.make(game);

    // Starta spelet (ALLT ska vara skapat före)
    game.start();

    return 0;
}
