#include "PheonApplication.h"
#include "PheonUtils.h"

namespace Pheon {

	Application::Application(const char* WindowName, const int& WindowWidth, const int& WindowHeight,
		SDL_WindowFlags& WindowFlags, const bool& CustomTitlebar)
		:m_HasCustomTitlebar(CustomTitlebar), m_TitlebarRect(0, 0, WindowWidth, 32 * m_HasCustomTitlebar)
	{
		if (m_HasCustomTitlebar) 
			WindowFlags += SDL_WINDOW_BORDERLESS;

		m_Window = SDL_CreateWindow(WindowName, WindowWidth, WindowHeight + (32 * m_HasCustomTitlebar), WindowFlags);
		m_Renderer = SDL_CreateRenderer(m_Window, NULL);
	}

	Application::Application(const char* WindowName, const int& WindowWidth, const int& WindowHeight,
		SDL_WindowFlags& WindowFlags, const char* IconPath, const bool& CustomTitlebar)
		: m_HasCustomTitlebar(CustomTitlebar), m_TitlebarRect(0, 0, WindowWidth, 32)
	{
		if (m_HasCustomTitlebar)
			WindowFlags += SDL_WINDOW_BORDERLESS;

		m_Window = SDL_CreateWindow(WindowName, WindowWidth, WindowHeight + (32 * m_HasCustomTitlebar), WindowFlags);
		m_Renderer = SDL_CreateRenderer(m_Window, NULL);

		// Set Window Icon
		if (m_WindowIcon = SDL_LoadBMP(IconPath))
			SDL_SetWindowIcon(m_Window, m_WindowIcon);
	}

	Application::~Application()
	{
		SDL_DestroySurface(m_WindowIcon);
	}

	void Application::FullScreenWindow() 
	{
		m_IsWindowFullscreen = !m_IsWindowFullscreen;
		SDL_SetWindowFullscreen(m_Window, m_IsWindowFullscreen ? 0 : SDL_WINDOW_FULLSCREEN);
	}

	void Application::InitLoop(const int& FrameRate)
	{
		Start();

		Uint64 frameStart;
		Uint64 frameTime;
		const int frameDelay = 1000 / FrameRate;

		while (m_IsWindowOpen)
		{
			frameStart = SDL_GetTicks(); // Get start of frame

			SDL_RenderClear(m_Renderer);
			
			if (m_HasCustomTitlebar) 
			{
				Utils::SetRenderColour(m_Renderer, Colours::BoxBorderColour);
				SDL_RenderFillRect(m_Renderer, &m_TitlebarRect);
				Utils::SetRenderColour(m_Renderer, Colours::BackgroundColour);
			}

			Update();

			for (const auto& i : m_RenderQueue)
			{
				i->Render();
			}

			SDL_RenderPresent(m_Renderer);

			frameTime = SDL_GetTicks() - frameStart; // Get time frame has elapsed

			// If x pressed close window
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_EVENT_QUIT:
					m_IsWindowOpen = false;
					break;
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					m_IsMouseClicked = true;
					break;
				case SDL_EVENT_MOUSE_BUTTON_UP:
					m_IsMouseClicked = false;
					
					for (const auto& i : m_RenderQueue) 
					{
						i->OnMouseUp();
					}
					
					break;
				case SDL_EVENT_WINDOW_SHOWN:
					SDL_GetWindowSize(m_Window, &m_WindowWidth, &m_WindowHeight);
					break;
				case SDL_EVENT_WINDOW_RESIZED:
					SDL_GetWindowSize(m_Window, &m_WindowWidth, &m_WindowHeight);
					m_TitlebarRect = { 0,0, (float)m_WindowWidth, 32 };
					break;

				default:
					break;
				}

				OnEvent(event);
			}

			if (frameDelay > frameTime)
				SDL_Delay(frameDelay - frameTime); // Delay next frame
		}
	}

	void Application::CloseWindow() 
	{
		m_IsWindowOpen = false;
	}

	void Application::MinimiseWindow() 
	{
		SDL_MinimizeWindow(m_Window);
	}
}