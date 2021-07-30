#pragma once
#include <sstream>
#include "GameOverState.h"
#include "DEFINITIONS.h"

#include <iostream>

namespace Flappy
{
	GameOverState::GameOverState(GameDataRef data) : _data(data) {}

	void GameOverState::Init()
	{
		cout << "Game State wiiiii" << endl;
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
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
		}
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		this->_data->window.display();
	}
}