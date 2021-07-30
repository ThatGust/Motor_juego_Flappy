#pragma once
#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"

#include <iostream>

namespace Flappy
{
	GameState::GameState(GameDataRef data) : _data(data) {}

	void GameState::Init()
	{
		cout << "Game State wiiiii" << endl;
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

		//pipes
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);

		pipe = new Pipe(_data);

	}

	void GameState::HandleInput()
	{
		Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window))
			{
				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				
			}
		}
	}

	void GameState::Update(float dt)
	{
		pipe->MovePipes(dt);
		//pipes con frecuencia
		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FRECUENCY) {
			pipe->SpawnInvisiblePipe();
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();

			clock.restart();
		}
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		pipe->DrawPipes();

		this->_data->window.display();
	}
}