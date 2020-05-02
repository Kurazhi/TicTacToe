#include "Board.h"

void Board::editBoard(int row, int column, char c)
{
	mBoard[row][column] = c;
	occupiedSpaces++;
}
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

