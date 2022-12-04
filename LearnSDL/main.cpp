#include "Game.h"

game *Game = nullptr;

int main(int argc, char * argv[])
{
	Game = new game();

	Game->init("Star", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (Game->running())
	{
		Game->handleEvents();
		Game->update();
		Game->render();
	}

	Game->clean();



	return 0;
}