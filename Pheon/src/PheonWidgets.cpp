#include "PheonWidgets.h"

namespace Pheon 
{
	namespace Widgets
	{
		// Pheon Label
		PheonLabel::PheonLabel(const char* Text, Vector2* position, const float& Scale, Application* Application)
			: m_Position(position), m_Application(Application), m_Scale(Scale) 
		{
			m_Surface = TTF_RenderText_Solid(m_Application->m_MainFont, Text, NULL, Colours::TextColour);

			m_Texture = SDL_CreateTextureFromSurface(m_Application->m_Renderer, m_Surface);

			Application->m_RenderQueue.emplace_back(this);
		};

		void PheonLabel::UpdateText(const char* Text)
		{
			SDL_DestroySurface(m_Surface);
			SDL_DestroyTexture(m_Texture);

			m_Surface = TTF_RenderText_Solid(m_Application->m_MainFont, Text, NULL, Colours::TextColour);

			m_Texture = SDL_CreateTextureFromSurface(m_Application->m_Renderer, m_Surface);
		}

		void PheonLabel::Render()
		{
			m_Rect = { m_Position->x, m_Position->y, m_Texture->w * m_Scale, m_Texture->h * m_Scale };

			SDL_RenderTexture(m_Application->m_Renderer, m_Texture, NULL, &m_Rect);
		}

		PheonLabel::~PheonLabel()
		{
			SDL_DestroySurface(m_Surface);
			SDL_DestroyTexture(m_Texture);
		}

		// Pheon Button
		PheonButton::PheonButton(const char* ButtonText, SDL_FRect* ButtonRect, Application* Application)
			: m_Text(ButtonText), m_Rect(ButtonRect), app(Application)
		{
			TextPos = Pheon::Utils::CenterPosInRect(*m_Rect) - 
				Pheon::Utils::GetTextSize(m_Text, app->m_MainFont, 0.25f) / 2;

			Application->m_RenderQueue.emplace_back(this);
			
			m_label = new PheonLabel{ ButtonText , &TextPos, 0.25f , app };
		};

		void PheonButton::Render()
		{
			Pressed = false;

			if (Utils::IsMouseHoveringRect(*m_Rect))
			{
				while (SDL_PollEvent(&event))
				{
					if (event.type == SDL_EVENT_MOUSE_BUTTON_UP)
					{
						Utils::SetRenderColour(app->m_Renderer, Colours::ButtonColourPressed);
						SDL_RenderFillRect(app->m_Renderer, m_Rect);
						Pressed = true;
					}
					else
					{
						Utils::SetRenderColour(app->m_Renderer, Colours::ButtonColourHovered);
						SDL_RenderFillRect(app->m_Renderer, m_Rect);
						Pressed = false;
					} 
				}
				}
			else
			{
				Utils::SetRenderColour(app->m_Renderer, Colours::ButtonColour);
				SDL_RenderFillRect(app->m_Renderer, m_Rect);
				Pressed = false;
			}

			Utils::SetRenderColour(app->m_Renderer,Colours::ButtonBorderColour);
			SDL_RenderRect(app->m_Renderer, m_Rect);

			TextPos = Utils::CenterPosInRect(*m_Rect) - Utils::GetTextSize(m_Text, app->m_MainFont, 0.25f) / 2;

			Utils::SetRenderColour(app->m_Renderer, Colours::BackgroundColour);
		}

		PheonButton::~PheonButton() 
		{
			delete m_label;
		}

		// Pheon Image
		PheonImage::PheonImage(const char* FilePath, Vector2* pos, const float& Scale, Application* Application)
			: m_Pos(pos), m_Application(Application), m_Scale(Scale)
		{
			m_Surface = IMG_Load(FilePath);

			m_Texture = SDL_CreateTextureFromSurface(Application->m_Renderer, m_Surface);

			m_Rect = { pos->x,pos->y, m_Texture->w * Scale, m_Texture->h * Scale };

			Application->m_RenderQueue.emplace_back(this);
		};

		void PheonImage::Render()
		{
			m_Rect = { m_Pos->x,m_Pos->y,m_Texture->w * m_Scale,m_Texture->h * m_Scale };

			SDL_RenderTexture(m_Application->m_Renderer, m_Texture, NULL, &m_Rect);
		}

		PheonImage::~PheonImage() 
		{
			SDL_DestroyTexture(m_Texture);
			SDL_DestroySurface(m_Surface);
		}
	}
}