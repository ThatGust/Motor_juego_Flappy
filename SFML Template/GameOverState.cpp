#pragma once
#include <sstream>
#include "GameOverState.h"
#include "DEFINITIONS.h"
#include "GameState.h"


#include <iostream>

namespace Flappy
{
	GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score) {}

	void GameOverState::Init()
	{
		cout << "Game State wiiiii" << endl;
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);

		_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));

		_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));

		_gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Body"));

		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_gameOverContainer.setPosition((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.
			getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2 ));

		_gameOverTitle.setPosition((_data->window.getSize().x / 3) - (_gameOverContainer.getGlobalBounds().width / 2), _gameOverContainer.
			getPosition().y - (_gameOverContainer.getGlobalBounds().height * 1.2));

		_retryButton.setPosition((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _gameOverContainer.
			getPosition().y + _gameOverContainer.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2));


		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(80);
		_scoreText.setFillColor(sf::Color::White);

		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText
			.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 14 * 7.25, _data->window.getSize().y / 1.93);


		/*_highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(80);
		_highScoreText.setFillColor(sf::Color::Red);
		_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText
			.getGlobalBounds().height / 2);
		_highScoreText.setPosition(_data->window.getSize().x / 12 * 7.25, _data->window.getSize().y / 1.78);
		*/

	}

	void GameOverState::HandleInput()
	{
		Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)) {
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		_data->window.draw(_gameOverTitle);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_retryButton);

		_data->window.draw(_scoreText);
		//_data->window.draw(_highScoreText);


		this->_data->window.display();
	}
}