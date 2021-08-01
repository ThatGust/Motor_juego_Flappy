#pragma once
#include <memory>
#include <stack>

#include "State.h"

using namespace std;

namespace Flappy {
	typedef unique_ptr<State> StateRef;
	//Maneja todo lo que esta corriendo
	class StateMachine {

	public:
		StateMachine() {}
		~StateMachine() {}
		//Reemplaza estados de manera dinamica
		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();

		void ProcessStateChanges();

		StateRef& GetActiveState();
	private:
		stack<StateRef> _states;
		StateRef _newState{};

		bool _isRemoving = true;
		bool _isAdding = true;
		bool _isReplacing = true;

	};
}