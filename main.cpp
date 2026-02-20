#include "Player.h"
#include "Weapon.h"
#include "Game.h"

/*
 *  TODO game logic class, controlling crit rates, etc.
 *  TODO skills class
 *  TODO make it look nice :)
 */

int main() {
    const Player player("Player1", 100, 10, 5);

    Game game(player);
    game.startGame();

    return 0;

}