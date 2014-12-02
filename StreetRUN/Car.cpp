#include "stdafx.h"
#include "Car.h"


Car::Car()
{
}


Car::~Car()
{
}

void Car::Push_Texture(std::string Path, std::string Index)
{
	LoadTexture::Instance()->PushTexture(Path, Index);
}


SDL_Texture* Car::GetCar(std::string Index)
{
	return LoadTexture::Instance()->GetTexture(Index);
}

SDL_Renderer* Car::GetRender()
{
	return LoadTexture::Instance()->GetRenderer();
}

void Car::Render(std::string Index,int PosX, int PosY)
{
	SDL_Rect src;
	src.h = 200;
	src.w = 200;
	src.x = 0;
	src.y = 0;

	SDL_Rect dest;
	dest.h = 200;
	dest.w = 200;
	dest.x = PosX;
	dest.y = PosY;

	SDL_RenderCopy(GetRender(), LoadTexture::Instance()->GetTexture(Index), &src, &dest);
}