#include <iostream>

#include <SDL3/SDL.h>

int main()
{
	// Create Window
	const int wWidth = 900, wHeight = 600;
	SDL_Window* pWindow = SDL_CreateWindow("Renderer",wWidth,wHeight, SDL_WINDOW_HIGH_PIXEL_DENSITY);

	// Setup Update Loop
	bool appRunning = true;
	SDL_Event closeEvent;
	while (appRunning)
	{
		while (SDL_PollEvent(&closeEvent))
		{
			if (closeEvent.type == SDL_EVENT_QUIT) 
				appRunning = false;
		}

		// Update Loop
	}
}
