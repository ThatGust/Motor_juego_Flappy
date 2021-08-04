
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State.h"
#include "Game.h"
#include "PipeTwo.h"
#include "Land.h"
#include "Virus.h"
#include "Collision.h"
#include "Flash.h"
#include "HUD.h"
namespace Flappy
{
	class GameStateTwo : public State
	{
	public:
		GameStateTwo(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Sprite _background;

		PipeTwo* pipe;
		Land* land;
		Virus* virus;
		Collision* collision;

		Flash *flash;

		HUD* hud;

		sf::Clock clock;

		int _gameState;

		int _score;

		sf::SoundBuffer _hitSoundBuffer;
		sf::SoundBuffer _wingSoundBuffer;
		sf::SoundBuffer _pointSoundBuffer;

		sf::Sound _hitSound;
		sf::Sound _wingSound;
		sf::Sound _pointSound;

	};
}