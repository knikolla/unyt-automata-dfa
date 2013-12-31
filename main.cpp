#include <iostream>
#include <string>

#include "state.h"
#include "automaton.h"

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

    bool result = Automaton.decideString(std::string("1"));
    
	if (result == true) {
        std::cout << "Automaton accepted the string" << std::endl;
    } else {
        std::cout << "Automaton rejected the string" << std::endl;
    }
}