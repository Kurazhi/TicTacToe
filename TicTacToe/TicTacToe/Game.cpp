#include "Game.h"
void Game::render()
{
    std::cout << "============================\n";
    for (auto row : mBoard.getmBoard())
    {
        for (auto column : row)
            std::cout << column;
        std::cout << std::endl;
    }
    std::cout << "============================\n";
}
void Game::assignPlayers()
{
    players[0].setType('X');
    players[1].setType('O');
    
    players[0].setTurn(true);
    players[1].setTurn(false);
}
void Game::input()
{
    int x = 0, y = 0;
    bool correctAnswer{ false };
    while (!correctAnswer)
    {
        std::cout << "Choose x-value\n";
        std::cin >> x;
        std::cout << "Choose y-value\n";
        std::cin >> y;
        for (int i = 0; i < 2; i++)
        {
            if (players[i].isTurn())
            {
                if (mBoard.getChar(x, y) == 'X' || mBoard.getChar(x, y) == 'O')
                {
                    std::cout << "There's already something there! Try again!" << std::endl;
                    break;
                }
                mBoard.editBoard(y, x, players[i].getType());
                for (int i = 0; i < 2; i++)
                {
                    bool turn = players[i].isTurn();
                    players[i].setTurn(!turn);
                        
                }
                correctAnswer = true;
                break;
            }
        }
    }
   
}
void Game::close() 
{
    std::cout << "Bye Bye" << std::endl;
}
void Game::check()
{
    for (int i = 0; i < 2; i++)
    {
        if (mBoard.isWin(players[i].getType()))
        {
            std::cout << "player " << i + 1 << " wins" << std::endl;
            std::cout << "score " << players[i].getScore();
            players[i].incrementScore();
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
    char input;
    std::cout << "Press q to quit, else press r to replay";
    std::cin >> input;
    if (input == 'q')
    {
        quit = true;
    }
    else
        mBoard.restart();
}

