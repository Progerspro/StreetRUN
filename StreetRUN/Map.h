#pragma once

#include "LoadTexture.h"

class Map
{
public:
	Map();
	~Map();

	SDL_Renderer* GetRender();
	void Push_Texture(std::string, std::string);
	SDL_Texture* GetMap(std::string);
	void Render(std::string, int, int);
};

