#pragma once

#include "LoadTexture.h"
class Map
{
private:
	int RoadSpeed;
public:
	Map();
	~Map();

	SDL_Renderer* GetRender();
	void Push_Texture(std::string, std::string);
	SDL_Texture* GetMap(std::string);
	void Render(std::string, int, int);
	void HandleEvents(SDL_Event*);
	void MoveTheMap();
};

