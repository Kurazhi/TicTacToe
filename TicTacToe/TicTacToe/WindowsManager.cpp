#include "WindowsManager.h"
SDL_Window* WindowsManager::mWindow = NULL;
SDL_Renderer* WindowsManager::mRenderer = NULL;
bool quit = false;
WindowsManager::WindowsManager()
{
}
// Creates all the essentials required for making a windows in SDL2
bool WindowsManager::init()
{
	game.assignPlayers();
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
		success = false;
	}
	mWindow = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (mWindow == NULL)
	{
		std::cerr << "Unable to create Window: " << SDL_GetError() << std::endl;
		success = false;
	}
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == NULL)
	{
		std::cerr << "Unable to create Renderer: " << SDL_GetError() << std::endl;
		success = false;
	}
	return success;
}
// De-allocates all objects on the heap
void WindowsManager::close()
{
	if (mRenderer != NULL)
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
	}
	if (mWindow != NULL)
	{
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
	SDL_Quit();
}
// Main game loop
void WindowsManager::running()
{
	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			
		}
		game.handleUpdate(&event);
		game.render();
		game.check();
	}
}
WindowsManager::~WindowsManager()
{
	if (mRenderer != NULL)
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
	}
	if (mWindow != NULL)
	{
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}
SDL_Renderer* WindowsManager::getRenderer()
{
	return mRenderer;
}