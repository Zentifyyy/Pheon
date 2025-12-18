#include "PheonApplication.h"

namespace Pheon {

	Application::Application(const char* WindowName, const int WindowWidth, const int WindowHeight,
		const SDL_WindowFlags WindowFlags)
	{
		// Create Renderer and window
		m_Window = SDL_CreateWindow(WindowName, WindowWidth, WindowHeight, WindowFlags);
		m_Renderer = SDL_CreateRenderer(m_Window, NULL);
	}

	Application::Application(const char* WindowName, const int WindowWidth, const int WindowHeight,
		const SDL_WindowFlags WindowFlags, const char* IconPath)
	{
		// Create Renderer and window
		m_Window = SDL_CreateWindow(WindowName, WindowWidth, WindowHeight, WindowFlags);
		m_Renderer = SDL_CreateRenderer(m_Window, NULL);

		// Set Window Icon
		if (m_WindowIcon = SDL_LoadBMP(IconPath)) {
			SDL_SetWindowIcon(m_Window, m_WindowIcon);
		}
	}

	Application::~Application()
	{
		SDL_DestroySurface(m_WindowIcon);
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

			Update();

			for (int i = 0; i < m_RenderQueue.size(); i++)
			{
				m_RenderQueue[i]->Render();
			}

			SDL_RenderPresent(m_Renderer);

			frameTime = SDL_GetTicks() - frameStart; // Get time frame has elapsed

			if (frameDelay > frameTime)
				SDL_Delay(frameDelay - frameTime); // Delay next frame

			// If x pressed close window
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_EVENT_QUIT:
					m_IsWindowOpen = false;
					break;

				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					m_IsMouseClicked = !m_IsMouseClicked;
					break;
				case SDL_EVENT_MOUSE_BUTTON_UP:
					m_IsMouseClicked = !m_IsMouseClicked;
					break;

				case SDL_EVENT_WINDOW_SHOWN:
					SDL_GetWindowSize(m_Window, &m_WindowWidth, &m_WindowHeight);
					break;
				case SDL_EVENT_WINDOW_RESIZED:
					SDL_GetWindowSize(m_Window, &m_WindowWidth, &m_WindowHeight);
					break;

				default:
					break;
				}

				OnEvent(&event);
			}
		}
	}

	void Application::CloseWindow() 
	{
		m_IsWindowOpen = false;
	}
}