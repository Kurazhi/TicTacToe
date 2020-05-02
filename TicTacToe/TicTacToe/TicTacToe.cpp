#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"


int main()
{
    Game game;
    game.assignPlayers();
    while (!game.quit)
    {
        game.render();
        game.input();
        game.check();
    }
    game.close();
    
    return 0;
}
