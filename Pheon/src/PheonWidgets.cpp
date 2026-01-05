#include "PheonWidgets.h"

namespace Pheon 
{
	namespace Widgets
	{
		// Pheon Label
		Label::Label(const char* Text, Vector2* position, const float& Scale, Application* Application)
			: m_Position(position), m_Application(Application), m_Scale(Scale) 
		{
			m_Surface = TTF_RenderText_Solid(m_Application->m_MainFont, Text, NULL, Colours::TextColour);

			m_Texture = SDL_CreateTextureFromSurface(m_Application->m_Renderer, m_Surface);

			Application->m_RenderQueue.emplace_back(this);
		};

		void Label::UpdateText(const char* Text)
		{
			SDL_DestroySurface(m_Surface);
			SDL_DestroyTexture(m_Texture);

			m_Surface = TTF_RenderText_Solid(m_Application->m_MainFont, Text, NULL, Colours::TextColour);

			m_Texture = SDL_CreateTextureFromSurface(m_Application->m_Renderer, m_Surface);
		}

		void Label::Render()
		{
			m_Rect = { m_Position->x, m_Position->y, m_Texture->w * m_Scale, m_Texture->h * m_Scale };

			SDL_RenderTexture(m_Application->m_Renderer, m_Texture, NULL, &m_Rect);
		}

		Label::~Label()
		{
			SDL_DestroySurface(m_Surface);
			SDL_DestroyTexture(m_Texture);
		}

		// Pheon Button
		Button::Button(const char* ButtonText, SDL_FRect& ButtonRect, Application* Application)
			: m_Text(ButtonText), m_Rect(ButtonRect), app(Application)
		{
			TextPos = Pheon::Utils::CenterPosInRect(m_Rect) - 
				Pheon::Utils::GetTextSize(m_Text, app->m_MainFont, 0.25f) / 2;

			Application->m_RenderQueue.emplace_back(this);
			
			m_label = new Label{ ButtonText , &TextPos, 0.25f , app };
		};

		void Button::OnMouseUp() 
		{
			if (Utils::IsMouseHoveringRect(m_Rect))
				Pressed = true;
		}

		void Button::Render()
		{
			if (Utils::IsMouseHoveringRect(m_Rect))
			{
				if (app->m_IsMouseClicked)
				{
					Utils::SetRenderColour(app->m_Renderer, Colours::ButtonColourPressed);
					SDL_RenderFillRect(app->m_Renderer, &m_Rect);
				}
				else
				{
					Utils::SetRenderColour(app->m_Renderer, Colours::ButtonColourHovered);
					SDL_RenderFillRect(app->m_Renderer, &m_Rect);
				} 
			}
			else
			{
				Utils::SetRenderColour(app->m_Renderer, Colours::ButtonColour);
				SDL_RenderFillRect(app->m_Renderer, &m_Rect);
				Pressed = false;
			}

			Utils::SetRenderColour(app->m_Renderer,Colours::ButtonBorderColour);
			SDL_RenderRect(app->m_Renderer, &m_Rect);

			TextPos = Utils::CenterPosInRect(m_Rect) - Utils::GetTextSize(m_Text, app->m_MainFont, 0.25f) / 2;

			Utils::SetRenderColour(app->m_Renderer, Colours::BackgroundColour);
		}

		Button::~Button() 
		{
			delete m_label;
		}

		// Pheon Image
		Image::Image(const char* FilePath, Vector2& pos, const float& Scale, Application* Application)
			: m_Position(pos), m_Application(Application), m_Scale(Scale)
		{
			m_Surface = IMG_Load(FilePath);

			m_Texture = SDL_CreateTextureFromSurface(Application->m_Renderer, m_Surface);

			m_Rect = { pos.x,pos.y, m_Texture->w * Scale, m_Texture->h * Scale };

			Application->m_RenderQueue.emplace_back(this);
		};

		void Image::Render()
		{
			m_Rect = { m_Position.x,m_Position.y,m_Texture->w * m_Scale,m_Texture->h * m_Scale };

			SDL_RenderTexture(m_Application->m_Renderer, m_Texture, NULL, &m_Rect);
		}

		Image::~Image() 
		{
			SDL_DestroyTexture(m_Texture);
			SDL_DestroySurface(m_Surface);
		}

		Vector2 Image::GetSize()
		{
			return { (float)m_Texture->w, (float)m_Texture->h };
		}

		// Pheon Image Button
		ImageButton::ImageButton(const char* FilePath, Vector2& pos, Application* Application):
			m_Position(pos), m_Application(Application)
		{
			m_Surface = IMG_Load(FilePath);
			m_Texture = SDL_CreateTextureFromSurface(Application->m_Renderer, m_Surface);

			m_Rect = { m_Position.x,m_Position.y, (float)m_Texture->w, (float)m_Texture->h };

			Application->m_RenderQueue.emplace_back(this);
		}

		ImageButton::~ImageButton()
		{
			SDL_DestroySurface(m_Surface);
			SDL_DestroyTexture(m_Texture);
		}

		void ImageButton::OnMouseUp()
		{
			if (Utils::IsMouseHoveringRect(m_Rect))
				Pressed = true;
			else
				Pressed = false;
		}

		void ImageButton::Render()
		{
			if (Utils::IsMouseHoveringRect(m_Rect))
			{
				SDL_SetTextureColorMod(m_Texture, 95, 95, 95);

				if (m_Application->m_IsMouseClicked)
					SDL_SetTextureColorMod(m_Texture, 80, 80, 80);
			}
			else
			{
				SDL_SetTextureColorMod(m_Texture, 100, 100, 100);
				Pressed = false;
			}

			SDL_RenderTexture(m_Application->m_Renderer, m_Texture, NULL, &m_Rect);
		}
	}
}