#include "ApplicationLayer.h"

ApplicationLayer::ApplicationLayer(const char* WindowName, const int WindowWidth, const int WindowHeight,
	const SDL_WindowFlags WindowFlags)
{
	m_Window = SDL_CreateWindow(WindowName, WindowWidth, WindowHeight, WindowFlags);
}