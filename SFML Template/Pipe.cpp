#include "Pipe.h"
#include <iostream>
namespace Flappy 
{
	Pipe::Pipe(GameDataRef data) :_data(data) {}
	
	void Pipe::SpawnBottomPipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);

		pipeSprites.push_back(sprite);
	}



	void Pipe::SpawnTopPipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x, 0);

		pipeSprites.push_back(sprite);
	}



	void Pipe::SpawnInvisiblePipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);

		sprite.setColor(Color(0, 0, 0, 0));
		pipeSprites.push_back(sprite);
	}
	void Pipe::MovePipes(float dt) {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			//sf::Vector2f position = pipeSprites.at(i).getPosition();
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else {
				float movement = PIPE_MOVEMENT_SPEED * dt;

				pipeSprites.at(i).move(-movement, 0);
			}
			
		}
		std::cout << pipeSprites.size() << std::endl; // print in console
	}

	void Pipe::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			_data->window.draw(pipeSprites.at(i));
		}
	}
}