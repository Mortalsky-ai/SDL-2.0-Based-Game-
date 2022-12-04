
#ifndef Game_h
#define Game_h

#include "SDL.h"
#include <iostream>


class game {

public:
	game();
	~game();

	void init(const char* game, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	int count = 0;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

};

#endif 