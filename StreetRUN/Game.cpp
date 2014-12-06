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
				
			}
		}
	}
	
	
	return Success;
}


void Game::Push_All_Textures()
{
	MainCar.Push_Texture("Img/CarSprites.png", "CarSprites");
	MainMap.Push_Texture("Img/road.png","Map");
	MainTrafic.Push_Texture("Img/CarSprites.png", "Cars");
	

}

void Game::Event_Handler(SDL_Event* EventType)
{
	MainCar.HandleEvents(EventType);
	MainMap.HandleEvents(EventType);
}


bool Game::Update()
{
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
	MainTrafic.Render("Cars");
	
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

