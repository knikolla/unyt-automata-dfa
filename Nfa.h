#ifndef __unyt_automata_dfa__Nfa__
#define __unyt_automata_dfa__Nfa__

#include <string>
#include <vector>
#include <map>

class State;
class Transition;

class Nfa
{
    public:
    void addState(State* state);
    void addTransition(char symbol, std::string* origin, std::string* destination);
    void decideString(std::string input);
    
    private:
    std::map<std::string, State*>* states;
    State* startState;
    State* currentState;
};

#endif