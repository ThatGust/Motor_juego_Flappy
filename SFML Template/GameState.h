#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Virus.h"
#include "Collision.h"

namespace Flappy
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Sprite _background;
		
		Pipe *pipe;
		Land *land; 
		Virus *virus;
		Collision *collision;

		sf::Clock clock;

		int _gameState;
	};
}