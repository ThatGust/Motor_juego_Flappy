#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>

namespace Flappy
{
    class Virus
    {
    public:
        Virus( GameDataRef data );
        void Draw ();
        void Animate (float dt);

    private:
        GameDataRef _data;

        sf::Sprite _virusSprite;
        std::vector<sf::Texture> _animationFrames;

        unsigned int _animationIterator;

        sf::Clock _clock;
    };    
}