#pragma once

namespace Flappy
{
	class State
	{
	public:
		//Inicializa el state
		virtual void Init() = 0;
		//Maneja los inputs en el state
		virtual void HandleInput() = 0;
		//Actualiza variables
		virtual void Update(float dt) = 0;
		//Dibuja despues de actualizar, dt = determina los frames 
		virtual void Draw(float dt) = 0;
		//pausa el juego
		virtual void Pause();
		//Resume el juego
		virtual void Resume();
		
	};
}