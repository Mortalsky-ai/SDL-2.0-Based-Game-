#include "Game.h"

// Defining pointer
game *Game = nullptr;

int main(int argc, char * argv[])
{
	// Assigning value 
	Game = new game();

	// Initating window
	Game->init("Star", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	// Game loop
	while (Game->running())
	{
		Game->handleEvents();
		Game->update();
		Game->render();
	}

	// Closing game 
	Game->clean();



	return 0;
}