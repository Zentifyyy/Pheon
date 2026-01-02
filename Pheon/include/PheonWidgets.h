#pragma once
#include "SDL3_image/SDL_image.h"
#include "PheonUtils.h"
#include "PheonApplication.h"
#include "PheonWidgetBase.h"

namespace Pheon 
{
	namespace Widgets
	{
		class PheonLabel: public PheonWidget 
		{
		public:

			PheonLabel(const char* Text, Vector2* position, const float& Scale, Application* Application);

			void UpdateText(const char* Text);

			void Render();
			
			~PheonLabel();

		private:
			Vector2* m_Position;
			SDL_FRect m_Rect{};
			float m_Scale;

			Application* m_Application = nullptr;
			SDL_Surface* m_Surface = nullptr;
			SDL_Texture* m_Texture = nullptr;
		};

		class PheonButton : public PheonWidget 
		{
		public:

			PheonButton(const char* ButtonText, SDL_FRect& ButtonRect, Application* Application);

			void Render();

			void OnMouseUp();

			operator bool() { return Pressed; };

			~PheonButton();

			bool Pressed = false;

		private:
			const char* m_Text;
			SDL_FRect& m_Rect;
			Vector2 TextPos{ 0,0 };
			PheonLabel* m_label;
			Application* app;
		};


		class PheonImage : public PheonWidget 
		{
		public:
			PheonImage(const char* FilePath, Vector2& pos, const float& Scale, Application* Application);

			~PheonImage();
		
			void Render();

			Vector2 GetSize();

		private:
			SDL_FRect m_Rect{};
			Vector2& m_Position;
			float m_Scale;

			Application* m_Application = nullptr;
			SDL_Surface* m_Surface = nullptr;
			SDL_Texture* m_Texture = nullptr;
		};

		class PheonImageButton : public PheonWidget 
		{
		public:
			
			PheonImageButton(const char* FilePath, Vector2& pos, Application* Application);
			
			~PheonImageButton();

			operator bool() { return Pressed; }

			void OnMouseUp();

			void Render();

			bool Pressed = false;

		private:
			Vector2& m_Position;
			SDL_FRect m_Rect{};
			Application* m_Application = nullptr;
			SDL_Texture* m_Texture = nullptr;
			SDL_Surface* m_Surface = nullptr;
		};
	}
}