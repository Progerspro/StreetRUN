#include "stdafx.h"
#include "LoadMedia.h"



namespace Global_Data_LoadMedia
{
	SDL_Renderer* Global_Render;
}

LoadTexture::LoadTexture()
{
	
}


LoadTexture::~LoadTexture()
{
	Free_LoadTexture();
	
}

LoadTTF::LoadTTF()
{

}

LoadTTF::~LoadTTF()
{
	Free_LoadTTF();
}

void LoadTexture::ImageInit()
{
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cerr << "SDL_image could not initialize! SDL_image Error: \n" << IMG_GetError() << std::endl;
	}
	else
	{
		std::cout << "Init PNG was Successful!" << std::endl;
	}
}





void LoadTTF::Free_LoadTTF()
{
	Font_IsInit = false;
	Surface_Container.clear();
	Texture_Container.clear();
	Font = nullptr;
	TTF_Quit();
}
void LoadTexture::Free_LoadTexture()
{
	SDL_DestroyTexture(Temp_Texture_Get);
	SDL_FreeSurface(MainSurface);
	Temp_Texture_Get = nullptr;
	MainSurface = nullptr;
	IMG_Quit();
	
}

//Don't delete Checks if everything is good
void LoadTexture::GetRenderer()
{
	LocalRender = Global_Data_LoadMedia::Global_Render;
	if (LocalRender == NULL)
	{
		std::cerr << "ERROR! Could not import MainRender to LocalRender" << std::endl;
	}
}

//Work with Textures!
bool LoadTexture::CreateSurface(std::string Surface_Path,std::string Surface_Index)
{
	
	Surface_Container[Surface_Index] = (IMG_Load(Surface_Path.c_str()));
	if (Surface_Container[Surface_Index] == NULL)
	{
		std::cerr << "Could not load surface! because of SDL_Error: \n " << SDL_GetError() << std::endl;
		Success = false;
	}
	else
	{
		 SDL_SetColorKey(Surface_Container[Surface_Index], SDL_TRUE, SDL_MapRGB(Surface_Container[Surface_Index]->format, 255, 0, 255));
	}
	return Success;
}

bool LoadTexture::CreateTexture(std::string Index)
{
	Texture_Container[Index] = SDL_CreateTextureFromSurface(LocalRender, Surface_Container[Index]);
	if (Texture_Container[Index] == NULL)
	{
		std::cerr << "Failed to Create Texture From Surface! Because of SDL_Error: \n" << SDL_GetError() << std::endl;
		Success = false;
	}
	return Success;
}

bool LoadTexture::PushTexture(std::string Path_To_Surface, std::string Index)
{
	if (Image_IsInit == false)
	{
		ImageInit();
		Image_IsInit = true;
	}
	if (!CreateSurface(Path_To_Surface, Index))
	{
		std::cerr << "Failed to GetSurface!" << std::endl;
		Success = false;
	}
	else
	{
		if (!CreateTexture(Index))
		{
			std::cerr << "Failed to CreateTexture!" << std::endl;
			Success = false;
		}
	}
	return Success;
}
//End work with Textures


SDL_Texture* LoadTexture::GetTexture(std::string Texture_Index)
{
	Temp_Texture_Get = Texture_Container[Texture_Index];
	if (Temp_Texture_Get == NULL)
	{
		std::cerr << "Could not Get_Texture with Index " << Texture_Index << std::endl;
		return NULL;
	}
	else
	{
		return Temp_Texture_Get;
	}
}


bool LoadTTF::LoadFont(const std::string Path_To_Font,int Font_Size)
{
	Font = TTF_OpenFont(Path_To_Font.c_str(), Font_Size);
	if (Font == NULL)
	{
		std::cerr << "Could not open font " << TTF_GetError() << std::endl;
		Success = false;
	}
	return Success;
}

bool LoadTTF::CreateSurfaceText(const std::string Text,SDL_Color Text_Color,std::string TextIndex)
{
	
	Surface_Container[TextIndex] = TTF_RenderText_Solid(Font, Text.c_str(), Text_Color);
	if (Surface_Container[TextIndex] == NULL)
	{
		std::cerr << "Could not load font surface because of SDL_Error: \n " << TTF_GetError() << std::endl;
		Success = false;
	}
	return Success;
}

bool LoadTTF::CreateTextureText(std::string TextIndex)
{
	
	Texture_Container[TextIndex] = SDL_CreateTextureFromSurface (LocalRender, Surface_Container[TextIndex]);
	if (Texture_Container[TextIndex] == NULL)
	{
		std::cerr << "Could not create texture from surface! because of SDL_Error: \n " << TTF_GetError << std::endl;
		Success = false;
	}
	return Success;
}

bool LoadTTF::PushText(const std::string Font_Path, int Font_Size, std::string Text, SDL_Color Text_Color, std::string Index)
{
	if (!LoadFont(Path_To_Font, Font_Size))
	{
		std::cerr << "Could not LoadFont! Because of SDL_Error: \n" << TTF_GetError << std::endl;
	}
	else
	{
		if (!CreateSurfaceText(Text, Text_Color,Index))
		{
			std::cerr << "Could not make surface from the font!" << std::endl;
			Success = false;
		}
		else
		{
			if (!CreateTextureText(Index))
			{
				std::cerr << "Could not create texture from font surface!" << std::endl;
			}
		}
	}
		return Success;
}

void LoadTTF::FontInit()
{
	GetRenderer();
	if (TTF_Init() == -1)
		std::cerr << "Could not init ttf font! " << TTF_GetError() << std::endl;
}

int LoadTTF::GetFontWidth(std::string index)
{
	SDL_Surface* Temp_Surface = Surface_Container[index];
	if (Temp_Surface == NULL)
		std::cerr << "Could not take the width from the font surface" << std::endl;
	return Temp_Surface->w;
}

int LoadTTF::GetFontHeight(std::string index)
{
	SDL_Surface* Temp_Surface = Surface_Container[index];
	if (Temp_Surface == NULL)
	std::cerr << "Could not take the height from the font surface" << std::endl;
	return Temp_Surface->h;
}

void LoadTTF::GetRenderer()
{
	LocalRender = Global_Data_LoadMedia::Global_Render;
	if (LocalRender == NULL)
	{
		std::cerr << "ERROR! Could not import MainRender to LocalRender" << std::endl;
	}
}

int LoadTexture::GetImageWidth(std::string index)
{
	if (Surface_Container[index] == NULL)
	{
		std::cerr << "Could not take the width from the image surface" << std::endl;
		return NULL;
	}
	else
	{
		return Surface_Container[index]->w;
	}
}

int LoadTexture::GetImageHeight(std::string index)
{
	if (Surface_Container[index] == NULL)
	{
		std::cerr << "Could not take the width from the image surface" << std::endl;
		return NULL;
	}
	else
	{
		return Surface_Container[index]->h;
	}
}




