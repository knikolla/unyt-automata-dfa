#include <iostream>
#include <string>

#include "State.h"
#include "Automaton.h"

int main()
{
	Automaton Automaton;

    State a = State(std::string("A"));
	State b = State(std::string("B"));
	Automaton.addState(a);
	Automaton.addState(b);

	Automaton.getState(std::string("B"))->setAccepting(true);

	Automaton.addTransition('1', std::string("A"), std::string("B"));
	Automaton.addTransition('1', std::string("B"), std::string("A"));
	
	std::cout << Automaton.print() << std::endl;

	std::cout << Automaton.decideString(std::string("11")) << std::endl;

	std::string exitme;
	std::cin >> exitme;
}