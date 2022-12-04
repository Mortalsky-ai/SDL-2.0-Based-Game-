
#ifndef Game_h
#define Game_h

// Adding libraries
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


// Defining game class 
class game {

public:
	// Constructor
	game();
	~game();

	// Metods for game loop
	void init(const char* game, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	// Variables 
	int count = 0;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

};

#endif 