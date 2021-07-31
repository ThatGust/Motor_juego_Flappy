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
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		_data->assets.LoadTexture("Land", LAND_FILEPATH);
		_data->assets.LoadTexture("Virus Frame 1", VIRUS_FRAME_1_FILEPATH );

		pipe = new Pipe(_data);
		land = new Land(_data);
		virus = new Virus(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
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
		land->MoveLand( dt);

		//pipes con frecuencia
		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FRECUENCY) 
		{
			pipe->RandomisePipeOffset();
			
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
		land->DrawLand();
		virus->Draw( );
		
		this->_data->window.display();
	}
}