#pragma once
#include <map>
class LoadFont
{
private:
	//Data
	std::string Path_To_Font;
	bool Success = true;
	std::map<std::string, SDL_Texture*> Texture_Container;
	std::map<std::string, SDL_Surface*> Surface_Container;
	//Functions Font
	void Free_LoadFont();
	SDL_Renderer* GetRenderer();
	bool _LoadFont(std::string, int);//Load 2
	bool CreateSurfaceText(std::string, SDL_Color, std::string);//Create Surface Text 3
	bool CreateTextureText(std::string); //Create Texture

	SDL_Renderer* LocalRender = nullptr;
	bool Font_IsInit = false;
	int FontWidth, FontHeight;
	TTF_Font* Font = nullptr;


public:
	LoadFont();
	~LoadFont();

		void FontInit(); //Init 1
		bool PushText(std::string Font_Path, int Font_Size, std::string Text, SDL_Color Text_Color, std::string Index);

		SDL_Texture* GetText(std::string); //Main Function

		int GetTextWidth(std::string);
		int GetTextHeight(std::string);
	};

