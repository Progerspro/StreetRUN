#pragma once

#include "LoadTexture.h"
#include <windows.h>
//#include "RoadTrafic.h"
class Car
{
private:
	//This const is for moving left,right,up,down, not the map speed!
	const int MOVE_SPEED = 5;

	LoadTexture Car_Texture;
	int XVelocity = 0, YVelocity = 0;
	int XPos, YPos;
	std::string SpriteIndex[3];
	std::string ChoosenIndex;
	const Uint8* KeyBoardState;
	

public:
	Car();
	~Car();
	
	SDL_Renderer* GetRender();
	
	void Push_Texture(std::string, std::string);
	SDL_Texture* GetCar(std::string);
	void Render(std::string, int=0, int=0);
	void HandleEvents(SDL_Event* event);
	void Collision_Detect(SDL_Rect);
	void Move();
	//void Collision_Detection(RoadTrafic*);
};

