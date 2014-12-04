#include "stdafx.h"
#include "RoadTrafic.h"


RoadTrafic::RoadTrafic()
{
}


RoadTrafic::~RoadTrafic()
{
}

void RoadTrafic::CreateTraffic()
{
	
}

void RoadTrafic::GetCars(std::string Index)
{
	LocalTexture = Car::GetCar(Index);
	LocalRect[0] = {};
	LocalRect[1] = {};
	LocalRect[2] = {};
	LocalRect[3] = {};
}


int RoadTrafic::Generate_Random_Number(int Low_Num,int High_Num)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(Low_Num, High_Num);

    return dis(gen);

}

void RoadTrafic::Render(std::string Index,int Local_X_Pos,int Local_Y_Pos)
{

}

