#include "PheonApplication.h"
#include "PheonWidgets.h"
#include "SDL3_ttf/SDL_ttf.h"

class ExampleProject : public Pheon::Application{
public:

	using Application::Application;

	void OnEvent(SDL_Event* Event) override 
	{
		if(Event->type == SDL_EVENT_WINDOW_RESIZED || Event->type == SDL_EVENT_WINDOW_SHOWN)
			SDL_GetWindowSize(m_Window, &m_WindowWidth, &m_WindowHeight); // Update Screen Size
	}

	void Update() override
	{
		const SDL_FRect m_QuitButtonRect{ (float)m_WindowWidth - 110, (float)m_WindowHeight - 60, 100, 50 };
		if (Pheon::Widgets::Button("Quit", m_QuitButtonRect, this))
			CloseWindow();
	}

private:
	int m_WindowWidth{}, m_WindowHeight{};

	TTF_Font* m_MainFont = TTF_OpenFont("fonts/Roboto-Regular.ttf",500);
};

int main()
{
	TTF_Init();
	ExampleProject app("Pheon Project", 900,600, SDL_WINDOW_RESIZABLE,"img/icon.bmp");
	app.InitLoop(60);
}