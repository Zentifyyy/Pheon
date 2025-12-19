#pragma once
#include "SDL3_image/SDL_image.h"
#include "PheonUtils.h"
#include "PheonApplication.h"
#include "PheonWidgetBase.h"
#include <string>

namespace Pheon 
{
	namespace Widgets
	{
		class PheonLabel: public PheonWidget {
		public:

			PheonLabel(const char* Text, Vector2* position, const float& Scale, Application* Application);

			void UpdateText(const char* Text);

			void Render();
			
			~PheonLabel();

		public:
			Vector2* m_Position;
			SDL_FRect m_Rect{};
			float m_Scale;

			Application* m_Application = nullptr;

			SDL_Surface* m_Surface = nullptr;
			SDL_Texture* m_Texture = nullptr;
		};

		class PheonButton : public PheonWidget {
		public:

			PheonButton(const char* ButtonText, SDL_FRect* ButtonRect, Application* Application);

			void Render();

			operator bool() { return Pressed; };

			~PheonButton();

		public:

			bool Pressed = false;

			const char* m_Text;
			SDL_FRect* m_Rect;
			Vector2 TextPos{0,0};
			PheonLabel* m_label;
			Application* app;
		};


		class PheonImage : public PheonWidget {
		public:
			PheonImage(const char* FilePath, Vector2* pos, const float& Scale, Application* Application);

			~PheonImage();
		
			void Render();

		public:
			Vector2* m_Pos;

			float m_Scale;

			Application* m_Application = nullptr;

			SDL_Surface* m_Surface = nullptr;
			SDL_Texture* m_Texture = nullptr;

		private:
			SDL_FRect m_Rect{};
		};
	}
}