#include "PheonApplication.h"
#include "PheonWidgets.h"

class ExampleProject : public Pheon::Application {
public:

	Application::Application;

	void Start() override {}

	void OnEvent(SDL_Event* Event) override
	{
		if (Event->type == SDL_EVENT_WINDOW_RESIZED || Event->type == SDL_EVENT_WINDOW_SHOWN)
		{
			m_QuitButtonRect = { (float)m_WindowWidth - 110, (float)m_WindowHeight - 60, 100, 50 };

			m_LabelPos = { m_WindowWidth / 2 - Pheon::Utils::GetTextSize("Hello World", m_MainFont, .4f).x / 2, 100 };

			m_LogoPos = m_LabelPos - m_LogoOffset;
		}
	}

	void Update() override
	{
		if (m_ExitButton)
			CloseWindow();
	}

private:

	SDL_FRect m_QuitButtonRect{ 0,0,100,50 };

	Pheon::Vector2 m_LabelPos{ 0,0 };

	Pheon::Vector2 m_LogoPos{ 0,0 };
	const Pheon::Vector2 m_LogoOffset{ 50,0 };

	Pheon::Widgets::PheonLabel m_Label{ "Hello World", &m_LabelPos, 0.4f, this };

	Pheon::Widgets::PheonButton m_ExitButton{ "Exit", &m_QuitButtonRect, this };

	Pheon::Widgets::PheonImage m_Image{ "img/icon.bmp", &m_LogoPos , .175f, this };
};

int main()
{
	TTF_Init();

	ExampleProject app("Pheon Project", 900,600, SDL_WINDOW_RESIZABLE,"img/icon.bmp");
	app.InitLoop(60);

	TTF_Quit();
}