#include "Board.h"
#include "WindowsManager.h"
#include <cmath>
// Cell lengths
int Board::cellWidth = WindowsManager::screenWidth / 3;
int Board::cellHeight = WindowsManager::screenHeight / 3;

// Editor for the board
void Board::editBoard(int row, int column, char c)
{
	mBoard[row][column] = c;
	occupiedSpaces++;
}
// Clears the board 
void Board::restart()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mBoard[i][j] = '0';
		}
	}
	occupiedSpaces = 0;
}
// Verifies draw end of game
bool Board::isDraw()
{
	return occupiedSpaces >= 9;
}
bool Board::isWin(char c)
{
    for (int i = 0; i < 3; i++)
    {
        if ((mBoard[i][0] == c) && (mBoard[i][1] == c) && (mBoard[i][2] == c))
            return true;
        else if ((mBoard[0][i] == c) && (mBoard[1][i] == c) && (mBoard[2][i] == c))
            return true;
    }
    if ((mBoard[0][0] == c) && (mBoard[1][1] == c) && (mBoard[2][2] == c))
        return true;
    else if ((mBoard[0][2] == c) && (mBoard[1][1] == c) && (mBoard[2][0] == c))
        return true;
    else
        return false;

}
// Pieces Rendered
void Board::drawX(int row, int column)
{
    SDL_RenderDrawLine(WindowsManager::getRenderer(), column*cellWidth, row*cellHeight, column * cellWidth + cellWidth, row * cellHeight + cellHeight);
    SDL_RenderDrawLine(WindowsManager::getRenderer(), column * cellWidth, row * cellHeight + cellHeight, column * cellWidth + cellWidth, row * cellHeight);
}
void Board::drawO(int row, int col)
{

    int centerX = col * cellWidth + (cellWidth / 2);
    int centerY = row * cellHeight + (cellHeight / 2);
    int r = cellWidth / 2;
    double step = 2 * M_PI / 32;
    int endX = centerX + r;
    int endY = centerY;

    for (double angle = 0; angle < 2.3 * M_PI; angle += step)
    {
        int startX = endX;
        int startY = endY;
        endX = r * cos(angle) + centerX;
        endY = r * sin(angle) + centerY;
        SDL_RenderDrawLine(WindowsManager::getRenderer(), startX, startY, endX, endY);
    }
}

// Combination of all the rendering done by board
void Board::render()
{
    SDL_SetRenderDrawColor(WindowsManager::getRenderer(), 0x00, 0x00, 0x00, 0xFF);
    renderBoard();
    renderPieces();
    
}

void Board::renderBoard()
{
    SDL_RenderDrawLine(WindowsManager::getRenderer(),
        WindowsManager::screenWidth / 3, 0,
        WindowsManager::screenWidth / 3, WindowsManager::screenHeight);
    SDL_RenderDrawLine(WindowsManager::getRenderer(),
        WindowsManager::screenWidth / 3 * 2, 0,
        WindowsManager::screenWidth / 3 * 2, WindowsManager::screenHeight);
    SDL_RenderDrawLine(WindowsManager::getRenderer(),
        0, WindowsManager::screenHeight / 3,
        WindowsManager::screenWidth, WindowsManager::screenHeight / 3);
    SDL_RenderDrawLine(WindowsManager::getRenderer(),
        0, WindowsManager::screenHeight / 3 * 2,
        WindowsManager::screenWidth, WindowsManager::screenHeight / 3 * 2);
}

void Board::renderPieces()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (mBoard[i][j] == 'X')
                drawX(i, j);
            else if (mBoard[i][j] == 'O')
                drawO(i, j);
        }
}
