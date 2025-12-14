#pragma once
#include "SDL3_image/SDL_image.h"
#include "PheonApplication.h"
#include "PheonUtils.h"

namespace Pheon 
{
	namespace Widgets
	{
		class PheonButton{
		public:

			PheonButton(const char* ButtonText, SDL_FRect* ButtonRect, Application* Application);
		
			void Render();

		public:

			bool Pressed = false;

			const char* m_Text;
			SDL_FRect* m_Rect;
			SDL_FRect m_LabelPos{};

			Application* app;
		};

		class PheonLabel{
		public:

			PheonLabel(const char* Text, Vector2* position, const float& Scale, Application* Application);

			~PheonLabel();
		
			void Render();

		public:
			const char* m_Text;
			Vector2* m_Position;
			SDL_FRect m_Rect{};
			float m_Scale;

			Application* m_Application = nullptr;

			SDL_Surface* m_Surface = nullptr;
			SDL_Texture* m_Texture = nullptr;
		};

		class PheonImage{
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