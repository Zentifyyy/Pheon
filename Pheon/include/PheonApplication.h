#pragma once
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include "SDL3_ttf/SDL_ttf.h"
#include "PheonWidgetBase.h"
#include <vector>

namespace Pheon {

	// Create SDL_Window and SDL_Renderer.
	// Add a path to an icon .bmp to set the Window icon.
	// Run InitLoop() to keep the window open until the user closes it!
	class Application {
	public:
		
		Application(const char* WindowName, const int& WindowWidth, const int& WindowHeight,
			SDL_WindowFlags& WindowFlags, const bool& CustomTitlebar);

		Application(const char* WindowName, const int& WindowWidth, const int& WindowHeight,
			SDL_WindowFlags& WindowFlags, const char* IconPath, const bool& CustomTitlebar);

		~Application();

		// Initialise update loop with specific framerate
		void InitLoop(const int& FrameRate);

		// Define what happens every frame in your own file.
		virtual void Update() {};

		// Define what happens at the start of the application in your own file.
		virtual void Start() {};

		// Define what happens every time an SDL_Event is triggered in your own file.
		virtual void OnEvent(const SDL_Event& Event) {};
		
		// Close Current Window
		void CloseWindow();

		// Minimise Current Window
		void MinimiseWindow();

		// Toggle Fullscreen
		void FullScreenWindow();

		SDL_Window* m_Window = nullptr;

		SDL_Renderer* m_Renderer = nullptr;

		bool m_IsMouseClicked = false;

		int m_WindowWidth{}, m_WindowHeight{};

		TTF_Font* m_MainFont = TTF_OpenFont("fonts/Roboto-Regular.ttf", 100);

		std::vector<PheonWidget*> m_RenderQueue{};

	private:

		bool m_HasCustomTitlebar;
		SDL_FRect m_TitlebarRect;

		float MouseX{}, MouseY{};
		float GlobalMouseX{}, GlobalMouseY{};

		SDL_Event event{};

		bool m_IsWindowOpen = true;
		bool m_IsWindowFullscreen = true;

		SDL_Surface* m_WindowIcon = nullptr;
	};
}