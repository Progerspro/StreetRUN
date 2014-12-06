#include "stdafx.h"
#include "RoadTrafic.h"


RoadTrafic::RoadTrafic()
{
	Destination_Car_Position[0] = { 50,  0, 150, 314 };
	Destination_Car_Position[1] = { 300, 0, 150, 314 };
	Destination_Car_Position[2] = { 550, 0, 150, 314 };
	Destination_Car_Position[3] = { 800, 0, 150, 314 };
}


RoadTrafic::~RoadTrafic()
{
}

void RoadTrafic::Push_Texture(std::string Path, std::string Index)
{
	Car::Push_Texture(Path, Index);
}

void RoadTrafic::HandleCar(std::string Index,int PosX,int PosY,int Width,int Height)
{
	//if (Return_PosY() < -300)
	LocalTexture = Car::GetCar(Index);
	//Source car pos
	Source_Car_Position = { PosX, PosY, Width, Height };
}
void RoadTrafic::Car_Options(int Car_Speed, int Position_On_Road, int Show_Car_Interval)
{
	//Destination car pos
	MainSpeed = Car_Speed;
	MainDestination.x = Destination_Car_Position[Position_On_Road].x;
	MainDestination.w = Destination_Car_Position[Position_On_Road].w;
	MainDestination.h = Destination_Car_Position[Position_On_Road].h;
	TimeToRender = Show_Car_Interval;
}


int RoadTrafic::Generate_Random_Number(int Low_Num,int High_Num)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(Low_Num, High_Num);

    return dis(gen);

}

void RoadTrafic::Render()
{

	MainDestination.y += MainSpeed;
	std::cout << "MAINDESTINATION = " << MainDestination.y << std::endl << "MainSpeed = " << MainSpeed << std::endl;
	if (TimeToRender == 0)
	SDL_RenderCopy(Car::GetRender(), LocalTexture, &Source_Car_Position, &MainDestination);
}

int RoadTrafic::Return_PosX()
{
	LPosX = Source_Car_Position.x;
	return LPosX;
}

int RoadTrafic::Return_PosY()
{
	LPosY = Source_Car_Position.y;
	return LPosY;
}
//Bug with divide to zero FIX IT
int RoadTrafic::After_Seconds(int Sec)
{
   const static int Temp = Sec;
   return Sec % Temp;
}

//I think i need to move this to the Game.cpp
void RoadTrafic::Generate_Cars()
{
	bool Start_Generate;
	int Generate_Count;
	if (Start_Generate)
	{
		for (int a = 0; a < 4; a++)
		{
			Render();
		}
	}
}

