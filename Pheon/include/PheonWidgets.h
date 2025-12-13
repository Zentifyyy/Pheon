#pragma once
#include "SDL3_image/SDL_image.h"
#include "PheonApplication.h"
#include "PheonUtils.h"

namespace Pheon 
{
	namespace Widgets
	{
		bool Button(const char* ButtonText, const SDL_FRect& ButtonRect, Application* Application);

		void Label(const char* Text, const Vector2& position, const float& Scale, Application* Application);

		void Image(const char* FilePath, const Vector2& pos, const float& Scale, Application* Application);
	}
}