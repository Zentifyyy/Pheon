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
			
			const Vector2 TextPos = Pheon::Utils::CenterPosInRect(ButtonRect);
			Utils::SetRenderColour(Application->m_Renderer, Colours::TextColour);
			SDL_RenderDebugText(Application->m_Renderer, TextPos.x, TextPos.y, ButtonText);

			SDL_SetRenderDrawColor(Application->m_Renderer, 0, 0, 0, 255);

			return false;
		}
	}
}