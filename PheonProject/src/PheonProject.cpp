#include "PheonApplication.h"

void Pheon::Application::Update() 
{

}

int main()
{
	Pheon::Application app("Pheon Project", 900,600, SDL_WINDOW_RESIZABLE,"img/icon.bmp");
	app.InitLoop(60);
}