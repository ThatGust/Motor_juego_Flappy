#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Flappy
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Sprite _background;

		Sprite _gameOverTitle;
		Sprite _gameOverContainer;
		Sprite _retryButton;

		Text _scoreText;
		Text _highScoreText;

		int _score;
		//int _highScore;
	};
}