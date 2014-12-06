#include "stdafx.h"
#include "RoadTrafic.h"


RoadTrafic::RoadTrafic()
{
}


RoadTrafic::~RoadTrafic()
{
}

void RoadTrafic::Push_Texture(std::string Path, std::string Index)
{
	Car::Push_Texture(Path, Index);
}

void RoadTrafic::HandleCars(std::string Index)
{
	
	/*//LocalTexture = Car::GetCar(Index);
	//Source car pos
	Source_Car_Position[0] = { 0, 0, 150, 190 };
	Source_Car_Position[1] = { 151, 0, 150, 190 };
	Source_Car_Position[2] = { 302, 0, 150, 190 };
	Source_Car_Position[3] = { 0, 0, 0, 0 };
	Source_Car_Position[4] = { 0, 0, 0, 0 };
	Car_Type["Blue_Car"] = Source_Car_Position[];
	Car_Type["Gray_Car"] = Source_Car_Position[];
	Car_Type["Porshe_Car"] = Source_Car_Position[];
	Car_Type["Audi_Car"] = Source_Car_Position[];
	Car_Type["Red_Car"] = Source_Car_Position[];
	Car_Type["White_With_Red_Car"] = Source_Car_Position[];
	//Destination car pos

	Destination_Car_Position[0] = {50,-30,150,314};
	Destination_Car_Position[1] = {300,-30,150,314};
	Destination_Car_Position[2] = {550,-30,150,314};
	Destination_Car_Position[3] = {800,-30,150,314};
	*/
}

void RoadTrafic::Car_Options(int Car_Speed, int Position_On_Road, int Show_Car_Interval)
{

}


int RoadTrafic::Generate_Random_Number(int Low_Num,int High_Num)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(Low_Num, High_Num);

    return dis(gen);

}

void RoadTrafic::Render(std::string Index)
{
	/*SDL_Rect Dest;

	Dest.x = 50; //Generate_Random_Number(10, 800);
	Dest.y = TheMap.GetRoadSpeed();//Generate_Random_Number(-50, -30);
//	Dest.w = Local_Rect_Src->w;
	//Dest.h = Local_Rect_Src->h; 
	for (int a = 0; a <= 2;a++)
	//SDL_RenderCopy(Car::GetRender(), LocalTexture, &Local_Rect_Src[a], &Dest);*/
}

int RoadTrafic::Return_PosX()
{
	return PosX;
}

int RoadTrafic::Return_PosY()
{
	return PosY;
}

