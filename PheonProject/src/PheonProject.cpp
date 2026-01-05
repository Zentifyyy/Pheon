#include "PheonApplication.h"
#include "PheonWidgets.h"

class ExampleProject : public Pheon::Application {
public:

	Application::Application;

	void Start() override {}

	void OnEvent(const SDL_Event& Event) override
	{
		if (Event.type == SDL_EVENT_WINDOW_RESIZED or Event.type == SDL_EVENT_WINDOW_SHOWN or Event.type)
		{
			m_QuitButtonRect = { (float)m_WindowWidth - 110, (float)m_WindowHeight - 60, 100, 50 };

			m_LabelPos = { m_WindowWidth / 2 - Pheon::Utils::GetTextSize("Hello World", m_MainFont, .4f).x / 2, 100 };

			m_LogoPos = m_LabelPos - m_LogoOffset;

			BackgroundRect = { m_LogoPos.x - 10, m_LogoPos.y - 5, 275, 55 };
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

	SDL_FRect m_TestButtonPos{ 400,500, 100, 50 };

	Pheon::Vector2 m_ImageButtonPos{ 100,300 };

	SDL_FRect BackgroundRect{ 0,0,0,0 };
	Pheon::Widgets::ContentBox Background{ BackgroundRect,Pheon::Colours::BoxColour,Pheon::Colours::BoxBorderColour,this };

	Pheon::Widgets::Label m_Label{ "Hello World", &m_LabelPos, 0.4f, this };

	Pheon::Widgets::Button m_ExitButton{ "Exit", m_QuitButtonRect, this };

	Pheon::Widgets::Button m_TestButton{ "bleh", m_TestButtonPos, this };

	Pheon::Widgets::Image m_Image{ "img/icon.bmp", m_LogoPos , .175f, this };
};

int main()
{
	TTF_Init();

	ExampleProject app("Pheon Project", 900,600, SDL_WINDOW_RESIZABLE,"img/icon.bmp");
	app.InitLoop(60);

	TTF_Quit();
}