#pragma once

#include <map>

#include "StateMachine.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Flappy {
	class AssetManager
	{
	public:
		AssetManager() {};
		~AssetManager() {};

		void LoadTexture(string name, string fileName);
		Texture& GetTexture(string name);

		void LoadFont(string name, string fileName);
		Font& GetFont(string name);
	private:
		map<string, Texture> _textures;
		map<string, Font> _fonts;
	};


}