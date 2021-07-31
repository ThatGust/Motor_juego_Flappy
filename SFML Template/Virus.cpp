#include "Virus.h"

namespace Flappy
{
    Virus::Virus ( GameDataRef data ) : _data( data)
    {
        _animationIterator = 0;

        _animationFrames.push_back( _data->assets.GetTexture( "Virus Frame 1" ) );
        _animationFrames.push_back( _data->assets.GetTexture( "Virus Frame 2" ) );
        _animationFrames.push_back( _data->assets.GetTexture( "Virus Frame 3" ) );
        _animationFrames.push_back( _data->assets.GetTexture( "Virus Frame 4" ) );

        _virusSprite.setTexture( _animationFrames.at(_animationIterator) );
    }

    void Virus::Draw()
    {
        _data->window.draw( _virusSprite );
    }

    void Virus::Animate ( float dt)
    {
        if( _clock.getElapsedTime().asSeconds() > VIRUS_ANIMATION_DURATION/_animationFrames.size() )
        {
            if ( _animationIterator < _animationFrames.size() - 1 )
            {
                _animationIterator++;
            }
            else
            {
                _animationIterator = 0;
            }

            _virusSprite.setTexture( _animationFrames.at( _animationIterator ) );

            _clock.restart();
        }
    }
}