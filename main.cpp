#include <iostream>
#include <string>

#include "state.h"
#include "automaton.h"
#include "converter.h"

int main()
{
	Automaton automaton("../../nfa.txt");
//    
//    automaton.addSymbol('a');
//    State a = State(std::string("1"));
//	State b = State(std::string("2"));
//    automaton.addState(a);
//	automaton.addState(b);
//
//    automaton.getState(std::string("1"))->setAccepting(false);
//	automaton.getState(std::string("2"))->setAccepting(true);
//    
//	automaton.addTransition('a', std::string("1"), std::string("2"));
//    automaton.addTransition('e', std::string("2"), std::string("1"));
	//automaton.addTransition('a', std::string("2"), std::string("1"));
    
    Converter c(automaton);
    Automaton sresult = *c.convert();
	
	std::cout << sresult.print() << std::endl;

    bool result = sresult.decideString(std::string("aa"));
    
	if (result == true)
    {
        std::cout << "Automaton accepted the string" << std::endl;
    }
    else
    {
        std::cout << "Automaton rejected the string" << std::endl;
    }
}