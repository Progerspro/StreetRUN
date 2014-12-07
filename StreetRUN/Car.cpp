#include "stdafx.h"
#include "Car.h"


Car::Car()
{
	SpriteIndex[0] = "Car";
	SpriteIndex[1] = "Car_Left";
	SpriteIndex[2] = "Car_Right"; 
	XPos = 200;
	YPos = 200;
}


Car::~Car()
{
}

void Car::Push_Texture(std::string Path, std::string Index)
{
	LoadTexture::Instance()->PushTexture(Path, Index);
}


SDL_Texture* Car::GetCar(std::string Index)
{
	return LoadTexture::Instance()->GetTexture(Index);
}

SDL_Renderer* Car::GetRender()
{
	return LoadTexture::Instance()->GetRenderer();
}

void Car::Render(std::string Index, int LocalPosX, int LocalPosY)
{
	SDL_Rect src;
	SDL_Rect dest;
	//Default
	src.h = 290;
	src.w = 150;
	src.x = 0;
	src.y = 0;
	//Src
	if (ChoosenIndex == "Car")
	{
		src.h = 290;
		src.w = 150;
		src.x = 0;
		src.y = 0;
	}
	if (ChoosenIndex == "Car_Right")
	{
		src.h = 290;
		src.w = 165;
		src.x = 159;
		src.y = 0;
	}
	if (ChoosenIndex == "Car_Left")
	{
		src.h = 290;
		src.w = 168;
		src.x = 332;
		src.y = 0;
	}
	
	//Dest
	if (LocalPosX == 0 && LocalPosY == 0)
	{
		dest.h = 290;
		dest.w = 150;
		dest.x = XPos;
		dest.y = YPos;
	}
	else
	{
		dest.h = 290;
		dest.w = 150;
		dest.x = LocalPosX;
		dest.y = LocalPosY;
	}
	SDL_RenderCopy(GetRender(), LoadTexture::Instance()->GetTexture(Index), &src, &dest);
}


//For speed of moving
void Car::HandleEvents(SDL_Event* LocalEvent)
{
	//XVelocity and YVelocity
	if (LocalEvent->type == SDL_KEYDOWN && LocalEvent->key.repeat == 0)
	{
		switch (LocalEvent->key.keysym.sym)
		{

		case SDLK_UP:
			YVelocity -= MOVE_SPEED;
			ChoosenIndex = SpriteIndex[0];
			break;
		case SDLK_DOWN:
			YVelocity += MOVE_SPEED;
			ChoosenIndex = SpriteIndex[0];
			break;

		case SDLK_LEFT:
			XVelocity -= MOVE_SPEED;
			ChoosenIndex = SpriteIndex[1];
			break;

		case SDLK_RIGHT:
			XVelocity += MOVE_SPEED;
			ChoosenIndex = SpriteIndex[2];
			break;

				
		}
	}
	if (LocalEvent->type == SDL_KEYUP)
	{
		switch (LocalEvent->key.keysym.sym)
		{

		case SDLK_UP:
			YVelocity += MOVE_SPEED;
			ChoosenIndex = SpriteIndex[0];
			//Fix MOVE BUG
			KeyBoardState = SDL_GetKeyboardState(NULL);
			if (KeyBoardState[SDL_SCANCODE_LEFT] == 1)
				ChoosenIndex = SpriteIndex[1];
			if (KeyBoardState[SDL_SCANCODE_RIGHT] == 1)
				ChoosenIndex = SpriteIndex[2];
			if (KeyBoardState[SDL_SCANCODE_DOWN] == 1)
				ChoosenIndex = SpriteIndex[0];
			//END
			break;
		case SDLK_DOWN:
			YVelocity -= MOVE_SPEED;
			ChoosenIndex = SpriteIndex[0];
			//Fix MOVE BUG
			KeyBoardState = SDL_GetKeyboardState(NULL);
			if (KeyBoardState[SDL_SCANCODE_LEFT] == 1)
				ChoosenIndex = SpriteIndex[1];
			if (KeyBoardState[SDL_SCANCODE_RIGHT] == 1)
				ChoosenIndex = SpriteIndex[2];
			if (KeyBoardState[SDL_SCANCODE_UP] == 1)
				ChoosenIndex = SpriteIndex[0];
			//END
			break;

		case SDLK_LEFT:
			XVelocity += MOVE_SPEED;
			ChoosenIndex = SpriteIndex[0];
			//Fix MOVE BUG
			KeyBoardState = SDL_GetKeyboardState(NULL);
			if (KeyBoardState[SDL_SCANCODE_UP] == 1)
				ChoosenIndex = SpriteIndex[0];
			if (KeyBoardState[SDL_SCANCODE_RIGHT] == 1)
				ChoosenIndex = SpriteIndex[2];
			if (KeyBoardState[SDL_SCANCODE_DOWN] == 1)
				ChoosenIndex = SpriteIndex[0];
			//END
			break;

		case SDLK_RIGHT:
			XVelocity -= MOVE_SPEED;
			ChoosenIndex = SpriteIndex[0];
			//Fix MOVE BUG
			KeyBoardState = SDL_GetKeyboardState(NULL);
			if (KeyBoardState[SDL_SCANCODE_LEFT] == 1)
				ChoosenIndex = SpriteIndex[1];
			if (KeyBoardState[SDL_SCANCODE_UP] == 1)
				ChoosenIndex = SpriteIndex[0];
			if (KeyBoardState[SDL_SCANCODE_DOWN] == 1)
				ChoosenIndex = SpriteIndex[0];
			//END
			break;
		}
	}
}

void Car::Move()
{
	XPos += XVelocity;
	YPos += YVelocity;
	std::cout << "XVEL = " << XVelocity << std::endl;
	std::cout << "YVEL = " << YVelocity << std::endl;
	if (XPos < -25 || XPos + 150 > 1005)
		XPos -= XVelocity;
	std::cout << "Xpos = " << XPos << std::endl;
	
	if (YPos < -25 || YPos + 190 > 900)
		YPos -= YVelocity;
	std::cout << "Ypos = " << YPos << std::endl;
	
}

void Car::Collision_Detect(SDL_Rect Collision)
{
	/*if (YPos+290 == Collision.y)
	{
		MessageBox(NULL, L"Test", L"Test", NULL);
	}
	if (YPos + 290 == Collision.y)
	{
		MessageBox(NULL, L"Test", L"Test", NULL);
	}*/
	if (XPos + 150 >= Collision.x)
		std::cout << "XPos = " << XPos + 150 << std::endl << "Collision.x = " << Collision.x << std::endl;
		//MessageBox(NULL, L"Test", L"Test", NULL);
	if (XPos <= (Collision.x + 150))
		std::cout << "XPos = " << XPos << std::endl << "Collision.x = " << Collision.x + 150 << std::endl;
		//MessageBox(NULL, L"Test", L"Test", NULL);
	if (YPos + 290 >= Collision.y)
		std::cout << "YPos = " << YPos + 290 << std::endl << "Collision.y = " << Collision.y << std::endl;
		//MessageBox(NULL, L"Test", L"Test", NULL);
	if (YPos  <= (Collision.y + 300))
		std::cout << "YPos = " << YPos<< std::endl << "Collision.y = " << Collision.y + 300 << std::endl;
		//MessageBox(NULL, L"Test", L"Test", NULL);
}

/*void Car::Collision_Detection(RoadTrafic* Cars_Collision_Handle)
{

}*/


