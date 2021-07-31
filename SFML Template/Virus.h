#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

namespace Flappy
{
    class Virus
    {
    public:
        Virus( GameDataRef data );
        void Draw ();
    private:
        GameDataRef _data;

        sf::Sprite _virusSprite;
    };    
}