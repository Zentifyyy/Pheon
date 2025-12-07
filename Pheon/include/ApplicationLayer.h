#pragma once
#include "SDL3/SDL.h"

class ApplicationLayer
{
public:
	ApplicationLayer(const char* WindowName, const int WindowWidth, const int WindowHeight,
		const SDL_WindowFlags WindowFlags);

	SDL_Window* m_Window;

private:

};