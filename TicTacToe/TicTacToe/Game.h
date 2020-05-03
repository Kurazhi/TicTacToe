#pragma once
#include <iostream>
#include "Player.h"
#include "Board.h"
#include <SDl.h>
class Game
{
public:
	Game() : quit{ false }, players{'X', 'O'} {}
	void render();
	void assignPlayers();
	void check();
	void handleUpdate(SDL_Event* event);
	void close();
	bool quit;
private:
	Board mBoard;
	void rematch();
	Player players[2];
};

