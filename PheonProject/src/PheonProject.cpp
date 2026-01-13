#include "PheonApplication.h"
#include "PheonWidgets.h"

class ExampleProject : public Pheon::Application {
public:

	Application::Application;

	void Start() override {}

	void OnEvent(const SDL_Event& Event) override
	{
		if (Event.type == SDL_EVENT_WINDOW_RESIZED or Event.type == SDL_EVENT_WINDOW_SHOWN)
		{
			m_ExitButton.UpdateRect({ m_WindowWidth - 30.0f, 9, 16, 16 });
			m_WindowButton.UpdateRect({ m_WindowWidth - 60.0f, 9, 16, 16 });
			m_MinimiseButton.UpdateRect({ m_WindowWidth - 90.0f, 9, 16, 16 });

			m_LabelPos = { m_WindowWidth / 2 - Pheon::Utils::GetTextSize("Hello World", m_MainFont, .4f).x / 2, 100 };

			m_LogoPos = m_LabelPos - m_LogoOffset;

			BackgroundRect = { m_LogoPos.x - 10, m_LogoPos.y - 5, 275, 55 };
		}
	}

	void Update() override
	{
		if (m_ExitButton)
			CloseWindow();

		if (m_MinimiseButton)
			MinimiseWindow();

		if (m_WindowButton)
			FullScreenWindow();
	}

private:

	Pheon::Vector2<float> m_LabelPos{ 0,0 };

	Pheon::Vector2<float> m_LogoPos{ 0,0 };
	const Pheon::Vector2<float> m_LogoOffset{ 50,0 };

	SDL_FRect m_TestButtonPos{ 400,500, 100, 50 };

	SDL_FRect BackgroundRect{ 0,0,0,0 };
	Pheon::Widgets::ContentBox Background{ BackgroundRect,Pheon::Colours::BoxColour,Pheon::Colours::BoxBorderColour,this };

	Pheon::Widgets::Label m_Label{ "Hello World", &m_LabelPos, 0.4f, this };

	SDL_FRect m_ExitButtonRect{ 100,300, 16, 16 };
	Pheon::Widgets::ImageButton m_ExitButton{ "img/Exit.png", m_ExitButtonRect, this};

	SDL_FRect m_WindowButtonRect{ 100,300, 16, 16 };
	Pheon::Widgets::ImageButton m_WindowButton{ "img/Window.png", m_WindowButtonRect, this};

	SDL_FRect m_MinimiseButtonRect{ 100,300, 16, 16 };
	Pheon::Widgets::ImageButton m_MinimiseButton{ "img/Minimise.png", m_MinimiseButtonRect, this};

	Pheon::Widgets::Button m_TestButton{ "bleh", m_TestButtonPos, this };

	Pheon::Widgets::Image m_Image{ "img/icon.bmp", m_LogoPos , .175f, this };
};

int main()
{
	TTF_Init();

	SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE;
	ExampleProject app("Pheon Project", 900, 600, flags, "img/icon.bmp", true);
	app.InitLoop(60);

	TTF_Quit();
}