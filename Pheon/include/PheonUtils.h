#pragma once
#include "SDL3/SDL.h"

namespace Pheon 
{
	class Vector2
	{
	public:
		Vector2(const float& x, const float& y) : x(x), y(y) {};

		// If PositionOrSize == True, will return a Vector2 with the position.
		// If PositionOrSize == False, will return a Vector2 with the size.
		Vector2(const SDL_FRect& Rect, bool PositionOrSize);
	public:
		float x, y;
	};

	namespace Colours {

		const SDL_Color BackgroundColour{ 20, 20, 20, 255 };

		const SDL_Color ButtonColour{ 35, 35, 35, 255 };

		const SDL_Color ButtonColourHovered{ 25, 25, 25, 255 };

		const SDL_Color TextColour{ 255, 255, 255, 255 };

	}

	namespace Utils
	{
		bool IsMouseHoveringRect(const SDL_FRect& Rect);

		Pheon::Vector2 CenterPosInRect(const SDL_FRect& Rect);

		void SetRenderColour(SDL_Renderer* Renderer, const SDL_Color& Colour);
	}
}