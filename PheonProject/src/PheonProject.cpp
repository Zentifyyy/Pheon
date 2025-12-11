#include "PheonApplication.h"
#include "PheonWidgets.h"

class ExampleProject : public Pheon::Application{
public:

	using Application::Application;

	void OnEvent(SDL_Event* Event) override 
	{
		if (Event->type == SDL_EVENT_WINDOW_RESIZED || Event->type == SDL_EVENT_WINDOW_SHOWN)
		{
			m_QuitButtonRect = { (float)m_WindowWidth - 110, (float)m_WindowHeight - 60, 100, 50 };
		}
	}

	void Update() override
	{
		if (Pheon::Widgets::Button("Quit", m_QuitButtonRect, this))
			CloseWindow();


		Pheon::Vector2 Pos(100,100);
		Pheon::Widgets::Label("Hello World", this, Pos, .4f);
	}

private:
	SDL_FRect m_QuitButtonRect{};
};

int main()
{
	TTF_Init();

	ExampleProject app("Pheon Project", 900,600, SDL_WINDOW_RESIZABLE,"img/icon.bmp");
	app.InitLoop(60);

	TTF_Quit();
}