#include "PipeTwo.h"
#include <iostream>

namespace Flappy
{
	PipeTwo::PipeTwo(GameDataRef data) :_data(data)
	{
		_landHeight = data->assets.GetTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
	}

	void PipeTwo::SpawnBottomPipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}

	void PipeTwo::SpawnTopPipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}



	void PipeTwo::SpawnInvisiblePipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);

		sprite.setColor(Color(0, 0, 0, 0));
		pipeSprites.push_back(sprite);
	}

	void PipeTwo::SpawnScoringPipe() {
		Sprite sprite( _data->assets.GetTexture("Scoring Pipe"));
		sprite.setPosition( _data->window.getSize().x, 0);
		scoringPipes.push_back(sprite);
	}

	void PipeTwo::MovePipes(float dt) {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			//sf::Vector2f position = pipeSprites.at(i).getPosition();
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else {
				float movement = PIPE_TWO_MOVEMENT_SPEED * dt;

				pipeSprites.at(i).move(-movement, 0);
			}

		}

		for (unsigned short int i = 0; i < scoringPipes.size(); i++)
		{
			//sf::Vector2f position = pipeSprites.at(i).getPosition();
			if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width) {
				scoringPipes.erase(scoringPipes.begin() + i);
			} 
			else {
				float movement = PIPE_TWO_MOVEMENT_SPEED * dt;

				scoringPipes.at(i).move(-movement, 0);
			}

		}
		//std::cout << pipeSprites.size() << std::endl; // print in console
	}

	void PipeTwo::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			_data->window.draw(pipeSprites.at(i));
		}
	}

	void PipeTwo::RandomisePipeOffset()
	{
		_pipeSpawnYOffset = rand() % (_landHeight + 1);
	}

	const std::vector<sf::Sprite>& PipeTwo::GetSprites() const
	{
		return pipeSprites;
	}

	std::vector<sf::Sprite>& PipeTwo::GetScoringSprites()
	{
		return scoringPipes;
	}

}