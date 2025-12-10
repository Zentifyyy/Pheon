#pragma once
#include "SDL3/SDL.h"

namespace Pheon {

	// Create SDL_Window and SDL_Renderer.
	// Add a path to an icon .bmp to set the Window icon.
	// Run InitLoop() to keep the window open until the user closes it!
	class Application {
	public:
		
		Application(const char* WindowName, const int WindowWidth, const int WindowHeight,
			const SDL_WindowFlags WindowFlags);

		Application(const char* WindowName, const int WindowWidth, const int WindowHeight,
			const SDL_WindowFlags WindowFlags, const char* IconPath);

		~Application();

		// Initialise update loop with specific framerate
		void InitLoop(int FrameRate);

		// Define what happens every frame in your own file.
		virtual void Update() {};

		// Define what happens every time an SDL_Event is triggered in your own file.
		virtual void OnEvent(SDL_Event* Event) {};
		
		// Close Current Window
		void CloseWindow();

		SDL_Window* m_Window = nullptr;

		SDL_Renderer* m_Renderer = nullptr;

		bool m_IsMouseClicked = false;

	private:

		bool m_IsWindowOpen = true;

		SDL_Surface* m_WindowIcon = nullptr;
	};
}