#pragma once
#include <iostream>
#include "Player.h"
#include "Board.h"
class Game
{
public:
	Game() : mBoard{}, quit{ false }, players{'X', 'O'} {}
	void render();
	void assignPlayers();
	void input();
	void check();
	void close();
	bool isWin(char c);
	void rematch();
	bool quit;
private:
	Board mBoard;
	
	Player players[2];
};

