#pragma once
#include <vector>
#include "Player.h"
class Board
{
public:
	Board() : occupiedSpaces{ 0 } {}
	std::vector<std::vector<char>> getmBoard() { return mBoard; }
	void editBoard(int row, int column, char c);
	void restart();
	char getChar(int x, int y) { return mBoard[y][x]; }
	bool isWin(char c);
	bool isDraw();
	void render();
	// Drawing Player Characters
	static void drawX(int row, int column);
	static void drawO(int row, int column);
	// Based on screen size
	static int cellWidth;
	static int cellHeight;
	// Renderers
	void renderBoard();
	void renderPieces();
	int occupiedSpaces;
private:
	std::vector<std::vector<char>> mBoard
	{
		{'0', '0', '0'},
		{'0', '0', '0'},
		{'0', '0', '0'}
	};
	
};

