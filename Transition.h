#ifndef __unyt_automata_dfa__Transition__
#define __unyt_automata_dfa__Transition__

#include <iostream>

class State;

class Transition
{
	public:
		Transition(char, State&, State&);
		State& getOrigin();
		State& getDestination();
		char getSymbol();
		std::string print();

    private:
		char symbol;
		State& origin;
		State& destination;
};

#endif