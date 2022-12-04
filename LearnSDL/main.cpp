#include "Game.h"

// Defining pointer
game *Game = nullptr;

int main(int argc, char * argv[])
{
	// Variables for FPS Limit
	const int FPS = 60;
	const int FrameDelay = 1000 / FPS;
	Uint32 FrameStart;
	int FrameTime;

	// Assigning value 
	Game = new game();

	// Initating window
	Game->init("Star", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	// Game loop
	while (Game->running())
	{
		// Game start time
		FrameStart = SDL_GetTicks();

		// Game loop
		Game->handleEvents();
		Game->update();
		Game->render();

		// Time till game started
		FrameTime = SDL_GetTicks() - FrameStart;

		// Correction in Framerate
		if (FrameDelay > FrameTime)
		{
			SDL_Delay(FrameDelay - FrameTime);
		}

	}

	// Closing game 
	Game->clean();



	return 0;
}