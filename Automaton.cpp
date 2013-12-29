#include "Automaton.h"

#include <string>

#include "State.h"
#include "Transition.h"

void Automaton::addState(State& state)
{
	if (states.empty() == true)
	{
		startState = &state;
	}

	states[state.getName()] = &state;
}

State* Automaton::getState(std::string name)
{
	return states[name];
}

void Automaton::addTransition(char s, std::string o, std::string d)
{
	State* origin = states[o];
	State* destination = states[d];
	origin->addTransition(new Transition(s, *origin, *destination));
}

bool Automaton::decideString(std::string input)
{
	currentState = startState;

	for (int i = 0; i < input.size(); i++)
	{
		auto t = currentState->getTransitions(input.at(i))->front();
		currentState = &t->getDestination();
	}

	if (currentState->isAccepting() == true) {
		return true;
	}
	else return false;
}

std::string Automaton::print()
{
	std::string result = std::string("");
	for (auto s : states)
	{
		result.append(s.second->print());
	}
	return result;
}

