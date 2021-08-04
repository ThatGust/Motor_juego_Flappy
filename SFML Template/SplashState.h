
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Flappy
{//herencia de STATE
	class SplashState : public State
	{
	public:
		//constructor
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Clock _clock;

		Texture _backgroundTexture;
		Sprite _background;
	};
}