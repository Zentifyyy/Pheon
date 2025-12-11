#pragma once
#include "PheonApplication.h"
#include "PheonUtils.h"

namespace Pheon 
{
	namespace Widgets
	{
		bool Button(const char* ButtonText, const SDL_FRect& ButtonRect, Application* Application);

		void Label(const char* Text, Application* Application, const Vector2& position, const float& Scale);
	}
}