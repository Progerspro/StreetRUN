#include "stdafx.h"
#include "Map.h"


Map::Map()
{
}


Map::~Map()
{
}

void Map::Push_Texture(std::string Path, std::string Index)
{
	LoadTexture::Instance()->PushTexture(Path, Index);
}


SDL_Texture* Map::GetMap(std::string Index)
{
	return LoadTexture::Instance()->GetTexture(Index);
}

SDL_Renderer* Map::GetRender()
{
	return LoadTexture::Instance()->GetRenderer();
}

void Map::Render(std::string Index, int PosX, int PosY)
{
	SDL_Rect src;
	src.h = 1024;
	src.w = 1024;
	src.x = 0;
	src.y = 0;

	SDL_Rect dest;
	dest.h = 900;
	dest.w = 1020;
	dest.x = PosX;
	dest.y = PosY;

	SDL_RenderCopy(GetRender(), LoadTexture::Instance()->GetTexture(Index), &src, &dest);
}