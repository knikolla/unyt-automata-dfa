#ifndef __unyt_automata_dfa__Transition__
#define __unyt_automata_dfa__Transition__

#include <iostream>

class State;

class Transition
{
    private:
    char symbol;
    State* origin;
    State* destination;
    
    public:
    Transition(char symbol, State* origin, State* destination);
    State* getOrigin();
    State* getDestination();
    char getSymbol();
};

#endif