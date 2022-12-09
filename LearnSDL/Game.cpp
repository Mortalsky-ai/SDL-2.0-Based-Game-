#include "Game.h"
#include "texture.h"
#include "GameObject.h"

GameObject* hero;


// Constructor
game::game()
{}
game::~game()
{}

// Initiating game class
void game::init(const char *title, int xpos, int ypos, int width, int hight, bool fullscreen)
{
	// Variable tol store fullscreeen counter
	int flags = 0;

	// Check for fullscreen
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// Initaiting subsystem
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised!..." << std::endl;

		// Initaiting window
		window = SDL_CreateWindow(title, xpos, ypos, width, hight, flags);
		if (window)
		{
			std::cout << "window created" << std::endl;
		}

		// Initaiting subsystem
		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created!" << std::endl;
		}

		// boolen for check start
		isRunning = true;

		hero = new GameObject("assets/Hero.png", renderer, 0, 0);
		
		
	}
	else
	{
		isRunning = false;
	}

}

// Event control 
void game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

// Updating every change
void game::update()
{
	hero->Update();
}

// Passing updates to renderer
void game::render()
{
	SDL_RenderClear(renderer);
	hero->Render();
	SDL_RenderPresent(renderer);
}

// Closing Subsystem
void game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}

