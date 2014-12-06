#include "stdafx.h"
#include "Game.h"



Game::Game()
{
	
}


Game::~Game()
{
}


SDL_Renderer* Game::GetRenderer()
{
	return MainRenderer;
}


bool Game::Init(std::string WindowName, int Window_Width, int Window_Height, int PosX, int PosY, Uint32 Window_Flag)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Could not Init video by SDL_Init_Video, because of SDL_Error: \n" << SDL_GetError() << std::endl;
		Success = false;
	}
	else
	{
		MainWindow = SDL_CreateWindow(WindowName.c_str(), PosX, PosY, Window_Width, Window_Height, Window_Flag);
		if (MainWindow == NULL)
		{
			std::cerr << "Could not Create MainWindow, because of SDL_Error: \n" << SDL_GetError() << std::endl;
			Success = false;
		}
		else
		{
			MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (MainRenderer == NULL)
			{
				std::cerr << "Could not Create MainRenderer, because of SDL_Error: \n" << SDL_GetError() << std::endl;
				Success = false;
			}
			else
			{
				LoadTexture::Instance()->InitRenderer(MainRenderer);
				LoadFont::Instance()->InitRenderer(MainRenderer);
				MainText.SetFont("TTF/Font.ttf", 16);
				Push_All_Textures();
				for (int a = 0; a < 6; a++)
					MainTrafic[a] = new RoadTrafic;
				MainTrafic[0]->HandleCar("First_Car", 0, 0, 150, 300);
				MainTrafic[1]->HandleCar("Second_Car", 0, 0, 150, 388);
				MainTrafic[2]->HandleCar("Third_Car", 0, 0, 150, 308);
				MainTrafic[3]->HandleCar("Fourth_Car", 0, 0, 150, 300);
				MainTrafic[4]->HandleCar("Fifth_Car", 0, 0, 150, 313);
				MainTrafic[5]->HandleCar("Six_Car", 0, 0, 150, 309);
			}
		}
	}
	return Success;
}


void Game::Push_All_Textures()
{
	MainCar.Push_Texture("Img/CarSprites.png", "CarSprites");
	MainMap.Push_Texture("Img/road.png","Map");
	MainTrafic[0]->Push_Texture("Img/First_Car.png","First_Car");
	MainTrafic[1]->Push_Texture("Img/Second_Car.png","Second_Car");
	MainTrafic[2]->Push_Texture("Img/Third_Car.png","Third_Car");
	MainTrafic[3]->Push_Texture("Img/Fourth_Car.png","Fourth_Car");
	MainTrafic[4]->Push_Texture("Img/Fifth_Car.png","Fifth_Car");
	MainTrafic[5]->Push_Texture("Img/Six_Car.png","Six_Car");

}

void Game::Event_Handler(SDL_Event* EventType)
{
	MainCar.HandleEvents(EventType);
	MainMap.HandleEvents(EventType);
}


bool Game::Update()
{
	for (int a = 0; a < 6; a++)
		MainTrafic[a]->Car_Options(MainMap.GetRoadSpeed(), MainTrafic[a]->Generate_Random_Number(0, 3), MainTrafic[a]->After_Seconds(MainTrafic[a]->Generate_Random_Number(0, 30)));
	//This text updates the speed so don't move it to static push
	SDL_Color Text_Color = { 255, 255, 255, 255 };
	MainText.SetText(MainMap.GetRoadSpeed_For_Text(), "Speed", Text_Color);	//
	MainCar.Move();
	return true; //TEMP
}

bool Game::Render()
{
	//Render and move the map!
	MainMap.MoveTheMap();
	//Render the car
	MainCar.Render("CarSprites");
	MainText.Render_Text("Speed", 30, 880);
	for (int a = 0; a < 6; a++)
	MainTrafic[a]->Render();
	
	return true; // TEMP
}

void Game::Quit()
{
	SDL_DestroyWindow(MainWindow);
	SDL_RenderClear(MainRenderer);
	MainWindow = nullptr;
	MainRenderer = nullptr;
	SDL_Quit();
	exit(0);
}


