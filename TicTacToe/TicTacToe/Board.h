#pragma once
#include <vector>
#include "Player.h"
class Board
{
public:
	Board() : bDone{ false }, occupiedSpaces{ 0 } {}
	/*render();
	close();*/
	std::vector<std::vector<char>> getmBoard() { return mBoard; }
	bool isDone();
	void editBoard(int row, int column, char c);
	void restart();
	char getChar(int x, int y) { return mBoard[y][x]; }
	bool isWin(char c);
	// Need to implement
	bool isDraw();
	void render();
private:
	std::vector<std::vector<char>> mBoard
	{
		{'0', '0', '0'},
		{'0', '0', '0'},
		{'0', '0', '0'}
	};
	bool bDone;
	int occupiedSpaces;

};

