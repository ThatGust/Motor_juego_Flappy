#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
//using namespace std;

namespace Flappy {
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
		Vector2i GetMousePosition(RenderWindow& window);
	};

}
