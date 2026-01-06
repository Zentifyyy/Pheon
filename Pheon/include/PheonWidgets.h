#pragma once
#include "SDL3_image/SDL_image.h"
#include "PheonUtils.h"
#include "PheonApplication.h"
#include "PheonWidgetBase.h"

namespace Pheon 
{
	namespace Widgets
	{
		class Label: public PheonWidget 
		{
		public:

			Label(const char* Text, Vector2<float>* position, const float& Scale, Application* Application);

			void UpdateText(const char* Text);

			void Render() override;
			
			~Label();

		private:
			Vector2<float>* m_Position;
			SDL_FRect m_Rect{};
			float m_Scale;

			Application* m_Application = nullptr;
			SDL_Surface* m_Surface = nullptr;
			SDL_Texture* m_Texture = nullptr;
		};

		class Button : public PheonWidget 
		{
		public:

			Button(const char* ButtonText, SDL_FRect& ButtonRect, Application* Application);

			void Render() override;

			void OnMouseUp() override;

			operator bool() { return Pressed; };

			~Button();

			bool Pressed = false;

		private:
			const char* m_Text;
			SDL_FRect& m_Rect;
			Vector2<float> TextPos{ 0,0 };
			Label* m_label;
			Application* app;
		};


		class Image : public PheonWidget 
		{
		public:
			Image(const char* FilePath, Vector2<float>& pos, const float& Scale, Application* Application);

			~Image();
		
			void Render() override;

			Vector2<int> GetSize();

		private:
			SDL_FRect m_Rect{};
			Vector2<float>& m_Position;
			float m_Scale;

			Application* m_Application = nullptr;
			SDL_Surface* m_Surface = nullptr;
			SDL_Texture* m_Texture = nullptr;
		};

		class ImageButton : public PheonWidget 
		{
		public:
			
			ImageButton(const char* FilePath, Vector2<float>& pos, Application* Application);
			
			~ImageButton();

			operator bool() { return Pressed; }

			void OnMouseUp() override;

			void Render() override;

			bool Pressed = false;

		private:
			Vector2<float>& m_Position;
			SDL_FRect m_Rect{};
			Application* m_Application = nullptr;
			SDL_Texture* m_Texture = nullptr;
			SDL_Surface* m_Surface = nullptr;
		};

		class ContentBox : public PheonWidget {
		public:

			ContentBox(SDL_FRect& Rect, const SDL_Color& RenderColour, const SDL_Color& BorderColor, Application* Application)
				: m_RenderColour(RenderColour), m_Application(Application), 
					m_DrawBorder(true), m_BorderColour(BorderColor), m_Rect(Rect) 
			{
				Application->m_RenderQueue.emplace_back(this);
			};

			/*ContentBox(SDL_FRect& Rect, SDL_Color& RenderColour, Application* Application)
				: m_RenderColour(RenderColour), m_Application(Application), 
					m_DrawBorder(false), m_Rect(Rect) 
			{
				Application->m_RenderQueue.emplace_back(this);
			};*/

			void Render() override 
			{
				Utils::SetRenderColour(m_Application->m_Renderer, m_RenderColour);
				SDL_RenderFillRect(m_Application->m_Renderer, &m_Rect);

				if (m_DrawBorder) 
				{
					Utils::SetRenderColour(m_Application->m_Renderer, m_BorderColour);
					SDL_RenderRect(m_Application->m_Renderer, &m_Rect);
				}	
			}

			const SDL_Color& m_RenderColour;
			const SDL_Color& m_BorderColour;

		private:
			SDL_FRect& m_Rect;
			const bool m_DrawBorder;
			Application* m_Application;
		};
		
	}
}