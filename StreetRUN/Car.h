#pragma once

#include "LoadTexture.h"
class Car
{
private:
	LoadTexture Car_Texture;
	SDL_Renderer* LocalRender;
public:
	Car();
	~Car();
	
	SDL_Renderer* GetRender();
	void Push_Texture(std::string, std::string);
	SDL_Texture* GetCar(std::string);
	void Render(std::string, int, int);
};

