#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[])
{
	//the window
	SDL_Window* window = NULL;
	
	//The surface on the window
	SDL_Surface* surface = NULL;
	
	//initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Could not initialize: " << SDL_GetError() << endl;
	}
	else
	{
		//create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if(window == NULL)
		{
			cout << "Window could not be created: " << SDL_GetError() << endl;
		}
		else
		{
			//get window surface
			surface = SDL_GetWindowSurface(window);
			
			//fill it white
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
			
			//update the surface
			SDL_UPdateWindow_Surface(window);
			
			//wait 2 seconds
			SDL_Delay(2000);
		}
	}
	
	//destroy window
	SDL_DestroyWindow(window);
	
	//quit SDL
	SDL_Quit();	

	return 0;
}