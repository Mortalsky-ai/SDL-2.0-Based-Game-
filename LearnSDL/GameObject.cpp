#pragma once
#include "texture.h"
#include "GameObject.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objectTexture = texture::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;

}

void GameObject::Update()
{
	xpos++;
	ypos++;
	
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = destRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objectTexture, &srcRect, &destRect);
}
