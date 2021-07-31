#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace Flappy
{
    class Land
    {
        public:
            Land( GameDataRef data );
            void MoveLand( float dt);
            void DrawLand();
        
        private:
            GameDataRef _data;

            std::vector<sf::Sprite> _landSprites;      
        
    };   
}