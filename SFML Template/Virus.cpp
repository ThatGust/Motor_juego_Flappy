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
        _virusSprite.setPosition( (_data->window.getSize().x/4) - ( _virusSprite.getGlobalBounds().width/2),  (_data->window.getSize().y/2 ) - (_virusSprite.getLocalBounds().height/2) );

        _virusState = VIRUS_STATE_STILL;

        sf::Vector2f origin = sf::Vector2f( _virusSprite.getGlobalBounds().width/2, _virusSprite.getGlobalBounds().height/2 );

        _virusSprite.setOrigin (origin);
        _rotation = 0;
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

    void Virus::Update ( float dt) 
    {
        if ( VIRUS_STATE_FALLING == _virusState )
        {
            _virusSprite.move(0, GRAVITY * dt );
            
            _rotation += ROTATION_SPEED * dt;
            if ( _rotation < -25.0f )
            {
                _rotation = -25.0f;
            }
        }
        else if ( VIRUS_STATE_FLAYING == _virusState )
        {
            _virusSprite.move( 0, -FLYING_SPEED * dt);
        }

        if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION )
        {
            _movementClock.restart();
            _virusState = VIRUS_STATE_FALLING;
        }
    }

    void Virus::Tap ()
    {
        _movementClock.restart();
        _virusState = VIRUS_STATE_FLAYING;
    }
}