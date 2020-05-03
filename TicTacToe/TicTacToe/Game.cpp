#include "Game.h"
#include "WindowsManager.h"
// Refreshing the renderer
void Game::render()
{
    SDL_SetRenderDrawColor(WindowsManager::getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(WindowsManager::getRenderer());
    mBoard.render();
    SDL_RenderPresent(WindowsManager::getRenderer());
    
}
// Default assignments for the players
void Game::assignPlayers()
{
    players[0].setType('X');
    players[1].setType('O');
    
    players[0].setTurn(true);
    players[1].setTurn(false);
}

void Game::close() 
{
    std::cout << "Bye Bye" << std::endl;
}
// Verifying if game is complete
void Game::check()
{
    for (int i = 0; i < 2; i++)
    {
        if (mBoard.isWin(players[i].getType()))
        {
            std::cout << "player " << i + 1 << " wins" << std::endl;
            players[i].incrementScore();
            std::cout << "score " << players[i].getScore() << std::endl;
            rematch();
        }
        else if (mBoard.isDraw())
        {
            std::cout << "This game ends in a draw" << std::endl;
            rematch();
        }
    }
    
}

void Game::rematch()
{
    mBoard.restart();
    SDL_Delay(1000);
}
// Checking for player input
void Game::handleUpdate(SDL_Event* e)
{
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        int column = x / (WindowsManager::screenWidth / 3);
        int row = y / (WindowsManager::screenHeight / 3);
        if (mBoard.getChar(column, row) == '0')
        {
            for (int i = 0; i < 2; i++)
            {
                if (players[i].isTurn())
                {
                    mBoard.editBoard(row, column, players[i].getType());
                }
                bool turn = players[i].isTurn();
                players[i].setTurn(!turn);
            }
        }
    }
}