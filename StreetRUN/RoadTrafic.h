#pragma once
#include "Car.h"
#include "Map.h"
#include "Timer.h"
class RoadTrafic :
	public Car
{
private:
	int Rand;
	int LPosX, LPosY;
	int Seconds;
	SDL_Texture* LocalTexture;
	SDL_Rect Source_Car_Position;
	//For positions
	SDL_Rect Destination_Car_Position[4];
	//Main position take from Destination_Car_Position
	SDL_Rect MainDestination;
	Map TheMap;
	Timer MainTime;
	int TimeToRender;
	int MainSpeed;
public:
	RoadTrafic();
	~RoadTrafic();
	//Learn the technology of generating those numbers !IMPORTANT!
	int Generate_Random_Number(int,int);
	//Ok! Lets do it like objects with random every car options,because other code is ****(REMOVE THIS AFTER THE RELEASE)
	void Car_Options(int Car_Speed,int Position_On_Road,int Show_Car_Interval);
	void HandleCar(std::string,int,int,int,int);
	void Push_Texture(std::string,std::string);
	void Render();
	void MoveTraffic();
	void Generate_Cars();
	int After_Seconds(int);
	int Return_PosX();
	int Return_PosY();


};

