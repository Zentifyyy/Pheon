#pragma once
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include "SDL3_ttf/SDL_ttf.h"

namespace Pheon 
{
	class Vector2
	{
	public:
		Vector2(const float& x, const float& y) : x(x), y(y) {};

		// If PositionOrSize == True, will return a Vector2 with the position.
		// If PositionOrSize == False, will return a Vector2 with the size.
		Vector2(const SDL_FRect& Rect, bool PositionOrSize);

		const Vector2 operator / (int other) 
		{
			return Vector2(x /= other,y /= other);
		}

		const Vector2 operator - (const Vector2& other)
		{
			return Vector2(x - other.x, y - other.y);
		}

		const Vector2 operator + (const Vector2& other)
		{
			return Vector2(x + other.x, y + other.y);
		}


	public:
		float x, y;
	};

	namespace Colours {

		const SDL_Color BackgroundColour{ 20, 20, 20, 255 };

		const SDL_Color ButtonColour{ 35, 35, 35, 255 };
		const SDL_Color ButtonColourHovered{ 25, 25, 25, 255 };
		const SDL_Color ButtonColourPressed{ 15, 15, 15, 255 };
		const SDL_Color ButtonBorderColour{ 60, 60, 60, 255 };

		const SDL_Color TextColour{ 230, 230, 230, 255 };

		const SDL_Color BoxColour{ 25,25,25,255 };
		const SDL_Color BoxBorderColour{ 30,30,30,255 };

	}

	namespace Utils
	{
		bool IsMouseHoveringRect(const SDL_FRect& Rect);

		Pheon::Vector2 CenterPosInRect(const SDL_FRect& Rect);

		void SetRenderColour(SDL_Renderer* Renderer, const SDL_Color& Colour);

		Pheon::Vector2 GetTextSize(const char* Text, TTF_Font* Font, const float Scale);
	}
}