#include "Virus.h"

namespace Flappy
{
    Virus::Virus ( GameDataRef data ) : _data( data)
    {
        _virusSprite.setTexture( _data->assets.GetTexture("Virus Frame 1") );
    }

    void Virus::Draw()
    {
        _data->window.draw( _virusSprite );
    }
}