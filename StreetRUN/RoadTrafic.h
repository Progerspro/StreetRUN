#pragma once
#include "Car.h"
#include "Map.h"
class RoadTrafic :
	public Car
{
private:
	int Rand;
	int PosX, PosY;
	SDL_Texture* LocalTexture;
	SDL_Rect LocalRect[];
public:
	RoadTrafic();
	~RoadTrafic();
	//Learn the technology of generating those numbers !IMPORTANT!
	int Generate_Random_Number(int,int);
	void GetCars(std::string);
	void CreateTraffic();
	void Render(std::string,int,int);
	void MoveTraffic();


};

