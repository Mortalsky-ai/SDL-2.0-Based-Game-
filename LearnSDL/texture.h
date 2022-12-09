#pragma once

#include "Game.h"

class texture {

public:
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);

};