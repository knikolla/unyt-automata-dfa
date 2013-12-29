#ifndef __unyt_automata_dfa__Automaton__
#define __unyt_automata_dfa__Automaton__

#include <string>
#include <vector>
#include <map>

class State;
class Transition;

class Automaton
{
    public:
		void addState(State&);
		State* getState(std::string&);
		void addTransition(char symbol, std::string&, std::string&);
		bool decideString(std::string&);
		std::string print();
    
    private:
		std::map<std::string, State*> states;
		State* startState;
		State* currentState;
};

#endif