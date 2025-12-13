#include "PheonApplication.h"
#include "PheonWidgets.h"
#include <iostream>

class ExampleProject : public Pheon::Application{
public:

	using Application::Application;

	void Start() override 
	{
		std::cout << "Hello World\n";
	}

	void OnEvent(SDL_Event* Event) override 
	{
		if (Event->type == SDL_EVENT_WINDOW_RESIZED || Event->type == SDL_EVENT_WINDOW_SHOWN)
		{
			m_QuitButtonRect = { (float)m_WindowWidth - 110, (float)m_WindowHeight - 60, 100, 50 };
			
			m_LabelPos = { m_WindowWidth / 2 - Pheon::Utils::GetTextSize("Hello World", m_MainFont, .4f).x / 2, 100 };	
		}
	}

	void Update() override
	{
		if (Pheon::Widgets::Button("Quit", m_QuitButtonRect, this))
			CloseWindow();

		Pheon::Widgets::Label("Hello World", m_LabelPos, .4f, this);

		Pheon::Widgets::Image("img/icon.bmp", m_LabelPos - m_LogoOffset, .175f, this);
	}

private:
	SDL_FRect m_QuitButtonRect{};

	Pheon::Vector2 m_LabelPos{0,0};

	Pheon::Vector2 m_LogoPos{0,0};
	const Pheon::Vector2 m_LogoOffset{75,0};
};

int main()
{
	TTF_Init();

	ExampleProject app("Pheon Project", 900,600, SDL_WINDOW_RESIZABLE,"img/icon.bmp");
	app.InitLoop(60);

	TTF_Quit();
}