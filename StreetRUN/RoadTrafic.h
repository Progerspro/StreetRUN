#pragma once
#include "Car.h"
#include "Map.h"
#include <map>
class RoadTrafic :
	public Car
{
private:
	int Rand;
	int PosX, PosY;
	SDL_Texture* LocalTexture;
	std::map <std::string, SDL_Rect*> Car_Type;
	SDL_Rect Source_Car_Position[5];
	SDL_Rect Destination_Car_Position[4];
	Map TheMap;
public:
	RoadTrafic();
	~RoadTrafic();
	//Learn the technology of generating those numbers !IMPORTANT!
	int Generate_Random_Number(int,int);
	//Ok! Lets do it like objects with random every car options,because other code is ****(REMOVE THIS AFTER THE RELEASE)
	void Car_Options(int Car_Speed,int Position_On_Road,int Show_Car_Interval);
	void HandleCars(std::string);
	void Push_Texture(std::string,std::string);
	void Render(std::string);
	void MoveTraffic();
	int Return_PosX();
	int Return_PosY();


};

