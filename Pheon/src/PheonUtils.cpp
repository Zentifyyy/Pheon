#include "PheonUtils.h"

namespace Pheon 
{
	Vector2::Vector2(const SDL_FRect& Rect, bool PositionOrSize)
	{
		if (PositionOrSize) 
		{
			x = Rect.x;
			y = Rect.y;;
		}
		else 
		{
			x = Rect.w;
			y = Rect.h;
		}
	}

	namespace Utils
	{
		bool IsMouseHoveringRect(const SDL_FRect& Rect)
		{
			float mousePosX{}, mousePosY{};
			SDL_GetMouseState(&mousePosX, &mousePosY);

			if (mousePosY > Rect.y && mousePosY < Rect.y + Rect.h) {

				if (mousePosX > Rect.x && mousePosX < Rect.x + Rect.w)
					return true;
				else
					return false;
			}
			else
				return false;
		}

		Pheon::Vector2 CenterPosInRect(const SDL_FRect& Rect) 
		{
			return Pheon::Vector2(Rect.x + (Rect.w / 2), Rect.y + (Rect.h / 2));
		}

		void SetRenderColour(SDL_Renderer* Renderer, const SDL_Color& Colour)
		{
			SDL_SetRenderDrawColor(Renderer, Colour.r, Colour.g, Colour.b, Colour.a);
		}
	
		Pheon::Vector2 GetTextSize(const char* Text, TTF_Font* Font, const float Scale)
		{
			SDL_Surface* surface = TTF_RenderText_Solid(Font, Text, NULL, Colours::TextColour);
			
			const Vector2 size{ surface->w * Scale, surface->h * Scale };
			
			SDL_DestroySurface(surface);

			return size;
		}
	}
}