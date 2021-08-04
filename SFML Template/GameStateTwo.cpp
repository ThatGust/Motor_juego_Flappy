#pragma once
#include <sstream>
#include "GameStateTwo.h"
#include "DEFINITIONS.h"
#include "GameOverState.h"

#include <iostream>

namespace Flappy
{
	GameStateTwo::GameStateTwo(GameDataRef data) : _data(data) {}

	void GameStateTwo::Init()
	{
		cout << "Game State wiiiii" << endl;

		if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH)) {
			std::cout << "Error loading Hit Sound Effect" << std::endl;
		}

		if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH)) {
			std::cout << "Error loading Wing Sound Effect" << std::endl;
		}

		if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH)) {
			std::cout << "Error loading Point Sound Effect" << std::endl;
		}

		_hitSound.setBuffer(_hitSoundBuffer);
		_wingSound.setBuffer(_wingSoundBuffer);
		_pointSound.setBuffer(_pointSoundBuffer);

		_data->assets.LoadTexture("Game Background", GAME_TWO_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_TWO_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_TWO_FILEPATH);
		_data->assets.LoadTexture("Land", LAND_FILEPATH);
		_data->assets.LoadTexture("Virus Frame 1", VIRUS_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Virus Frame 2", VIRUS_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Virus Frame 3", VIRUS_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("Virus Frame 4", VIRUS_FRAME_4_FILEPATH);

		_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);

		_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		pipe = new PipeTwo(_data);
		land = new Land(_data);
		virus = new Virus(_data);

		flash = new Flash(_data);

		hud = new HUD( _data );

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

		_score = 0;

		hud->UpdateScore(_score);


		_gameState = GameStates::eReady;
	}

	void GameStateTwo::HandleInput()
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
				// Estas 3 lineas ya no estan en el codigo que aparece en 
				// el video 18, minuto 9:34
				// pipe->SpawnInvisiblePipe();
				// pipe->SpawnBottomPipe();
				// pipe->SpawnTopPipe();

				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying;
					virus->Tap();		// Mover el virus con clic de mouse

					_wingSound.play();
				}
			}
		}
	}

	void GameStateTwo::Update(float dt)
	{
		if (GameStates::eGameOver != _gameState)
		{
			virus->Animate(dt);
			land->MoveLand(dt);
		}
		if (GameStates::ePlaying == _gameState)
		{
			pipe->MovePipes(dt);
			//pipes con frecuencia
			if (clock.getElapsedTime().asSeconds() > PIPE_TWO_SPAWN_FRECUENCY)
			{
				pipe->RandomisePipeOffset();

				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();

				pipe->SpawnScoringPipe();

				clock.restart();
			}

			virus->Update(dt);

			std::vector<sf::Sprite> landSprites = land->GetSprites();
			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collision->CheckSpriteCollision(virus->GetSprite(), 0.7f, landSprites.at(i), 1.0f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();

					_hitSound.play();
				}
			}

			std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
			for (int i = 0; i < pipeSprites.size(); i++)
			{
				if (collision->CheckSpriteCollision(virus->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f))
				{
					// PIPE_SPAWN_FRECUENCY 2.5f
					// Modificar este valor en DEFINITIONS para que
					// la collision se modifique
					_gameState = GameStates::eGameOver;

					clock.restart();

					_hitSound.play();


				}
			}

			if (GameStates::ePlaying == _gameState) {
				std::vector<sf::Sprite>& scoringSprites = pipe->GetScoringSprites();
				for (int i = 0; i < scoringSprites.size(); i++)
				{
					if (collision->CheckSpriteCollision(virus->GetSprite(), 0.625f, scoringSprites.at(i), 8.0f))
					{
						// PIPE_SPAWN_FRECUENCY 2.5f
						// Modificar este valor en DEFINITIONS para que
						// la collision se modifique
						//std::cout << _score << std::endl;
						_score++;
						hud->UpdateScore(_score);

						scoringSprites.erase(scoringSprites.begin() + i);

						_pointSound.play();

					}
				}
			}

		}

		if (GameStates::eGameOver == _gameState) {
			flash->Show(dt);

			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
				_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
			}
		}
	}

	void GameStateTwo::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		pipe->DrawPipes();
		land->DrawLand();
		virus->Draw();

		flash->Draw();

		hud->Draw();

		this->_data->window.display();
	}
}