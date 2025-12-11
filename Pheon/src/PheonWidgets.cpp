#include "PheonWidgets.h"

namespace Pheon 
{
	namespace Widgets 
	{
		bool Button(const char* ButtonText, const SDL_FRect& ButtonRect, Pheon::Application* Application)
		{
			if (Utils::IsMouseHoveringRect(ButtonRect))
			{
				Utils::SetRenderColour(Application->m_Renderer,Colours::ButtonColourHovered);
				SDL_RenderFillRect(Application->m_Renderer, &ButtonRect);


				if (Application->m_IsMouseClicked)
					return true;
			}
			else
			{
				Utils::SetRenderColour(Application->m_Renderer, Colours::ButtonColour);
				SDL_RenderFillRect(Application->m_Renderer, &ButtonRect);
			}
			
			Vector2 TextPos = Pheon::Utils::CenterPosInRect(ButtonRect);
			TextPos - Pheon::Utils::GetTextSize(ButtonText, Application->m_MainFont,.4f) / 2;
			Label(ButtonText,Application, TextPos , .4f);

			SDL_SetRenderDrawColor(Application->m_Renderer, 0, 0, 0, 255);

			return false;
		}

		void Label(const char* Text, Application* Application, const Vector2& position, const float& Scale) 
		{
			SDL_Surface* surface = TTF_RenderText_Solid(Application->m_MainFont, Text, NULL, Colours::TextColour);

			SDL_Texture* texture = SDL_CreateTextureFromSurface(Application->m_Renderer, surface);

			const SDL_FRect TextureRect{position.x, position.y, texture->w * Scale, texture->h * Scale};
			
			SDL_RenderTexture(Application->m_Renderer,texture,NULL,&TextureRect);

			SDL_DestroySurface(surface);
			SDL_DestroyTexture(texture);
		}
	}
}