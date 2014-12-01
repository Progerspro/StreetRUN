#pragma once

#include <string>
#include <map>

namespace Global_Data_LoadMedia
{
	extern SDL_Renderer* Global_Render;
}

class LoadTexture
{
private:
	//DATA
	bool Success = true;
	std::map<std::string,SDL_Texture*> Texture_Container;
	std::map<std::string,SDL_Surface*> Surface_Container;
	
	
	//Functions
	void Free_LoadTexture();
	void GetRenderer();
	//Functions Surface
	void ImageInit();
	bool CreateSurface(std::string,std::string);
	bool CreateTexture(std::string);
	bool Image_IsInit = false;
	
	//SDL
	SDL_Surface* MainSurface = nullptr;
	SDL_Texture* Temp_Texture_Get = nullptr;
	SDL_Renderer* LocalRender = nullptr;
	
public:
	
	LoadTexture();
	~LoadTexture();
	//Image
	bool PushTexture(std::string Path_To_Surface, std::string Index);
	SDL_Texture* GetTexture(std::string);
	int GetImageWidth(std::string);
	int GetImageHeight(std::string);

};

class LoadTTF
{
private:
	//Data
	std::string Path_To_Font;
	bool Success = true;
	std::map<std::string,SDL_Texture*> Texture_Container;
	std::map<std::string,SDL_Surface*> Surface_Container;
	//Functions Font
	void Free_LoadTTF();
	void GetRenderer();
	bool LoadFont(std::string, int);//Load 2
	bool CreateSurfaceText(std::string, SDL_Color,std::string);//Create Surface Text 3
	bool CreateTextureText(std::string); //Create Texture

	SDL_Renderer* LocalRender = nullptr;
	bool Font_IsInit = false;
	int FontWidth, FontHeight;
	TTF_Font* Font = nullptr;
public:
	LoadTTF();
	~LoadTTF();

	void FontInit(); //Init 1
	bool PushText(std::string Font_Path, int Font_Size, std::string Text, SDL_Color Text_Color, std::string Index);
	
	bool WriteText(int PosX, int PosY); //Main Function

	int GetFontWidth(std::string);
	int GetFontHeight(std::string);
};

/* Not complete
class LoadSound
{
private:

public:
	LoadSound();
	~LoadSound();
};
*/