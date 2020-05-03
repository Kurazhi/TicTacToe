#pragma once
#include <SDL.h>
#include "Game.h"
class WindowsManager
{
public:
	// Screen Resolution
	static const int screenWidth = 600;
	static const int screenHeight = 600;

	WindowsManager();
	~WindowsManager();

	bool init();
	void running();
	void close();
	// Getters
	static SDL_Renderer* getRenderer();
private:
	static SDL_Window* mWindow;
	static SDL_Renderer* mRenderer;
	bool quit;
	SDL_Event event;
	Game game;

	
};

