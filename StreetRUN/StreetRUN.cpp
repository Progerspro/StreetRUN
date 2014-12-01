// StreetRUN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "Could not init everything because of SDL_Error: \n" << SDL_GetError() << std::endl;
	}
	else
	{
		//CONTINUE
	}

	return 0;
}

