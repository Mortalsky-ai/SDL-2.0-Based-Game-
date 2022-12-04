#include "Game.h"

// Texture Variable
SDL_Texture* heroTex;

// TexVariable Parameters
SDL_Rect srcR, destR;

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

		SDL_Surface* tmpSurface = IMG_Load("assets/Hero.png");
		if (tmpSurface)
		{
			heroTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
			std::cout << "HERO IS HERE!" << std::endl;
		}
		else
		{
			std::cout << "HERO IS SLEEPING!" << std::endl;

		}
		
		SDL_FreeSurface(tmpSurface);
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
	count++;

	// Hero hight and width
	destR.h = 30;
	destR.w = 3;
	destR.x = 10;

	std::cout << count << std::endl;
}

// Passing updates to renderer
void game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, heroTex, NULL, NULL);
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

