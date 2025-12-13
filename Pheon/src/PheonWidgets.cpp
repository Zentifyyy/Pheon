#include "PheonWidgets.h"

namespace Pheon 
{
	namespace Widgets
	{
		bool Button(const char* ButtonText, const SDL_FRect& ButtonRect, Pheon::Application* Application)
		{
			if (Utils::IsMouseHoveringRect(ButtonRect))
			{
				if (!Application->m_IsMouseClicked) {
					Utils::SetRenderColour(Application->m_Renderer, Colours::ButtonColourHovered);
					SDL_RenderFillRect(Application->m_Renderer, &ButtonRect);
				}
				else
				{
					Utils::SetRenderColour(Application->m_Renderer, Colours::ButtonColourPressed);
					SDL_RenderFillRect(Application->m_Renderer, &ButtonRect);
					return true;
				}
			}
			else
			{
				Utils::SetRenderColour(Application->m_Renderer, Colours::ButtonColour);
				SDL_RenderFillRect(Application->m_Renderer, &ButtonRect);
			}

			const Vector2 TextPos = Pheon::Utils::CenterPosInRect(ButtonRect) -
				Pheon::Utils::GetTextSize(ButtonText, Application->m_MainFont, ButtonRect.w * ButtonRect.h / 30000) / 2;

			Label(ButtonText, TextPos, ButtonRect.w * ButtonRect.h / 30000, Application);

			SDL_SetRenderDrawColor(Application->m_Renderer, 0, 0, 0, 255);

			return false;
		}

		void Label(const char* Text, const Vector2& position, const float& Scale, Application* Application)
		{
			SDL_Surface* surface = TTF_RenderText_Solid(Application->m_MainFont, Text, NULL, Colours::TextColour);

			SDL_Texture* texture = SDL_CreateTextureFromSurface(Application->m_Renderer, surface);

			const SDL_FRect TextureRect{ position.x, position.y, texture->w * Scale, texture->h * Scale };

			SDL_RenderTexture(Application->m_Renderer, texture, NULL, &TextureRect);

			SDL_DestroySurface(surface);
			SDL_DestroyTexture(texture);
		}

		void Image(const char* FilePath,const Vector2& pos, const float& Scale,Application* Application)
		{
			SDL_Surface* surface = IMG_Load(FilePath);

			SDL_Texture* texture = SDL_CreateTextureFromSurface(Application->m_Renderer,surface);

			const SDL_FRect rect{pos.x,pos.y,texture->w * Scale,texture->h * Scale};

			SDL_RenderTexture(Application->m_Renderer,texture,NULL, &rect);
			SDL_DestroyTexture(texture);
			SDL_DestroySurface(surface);
		}
	}
}