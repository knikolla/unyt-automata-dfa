#ifndef __unyt_automata_dfa__converter__
#define __unyt_automata_dfa__converter__

#include <iostream>
#include <map>
#include <bitset>

#include "state.h"
#include "automaton.h"

class Converter
{
    
public:
    Converter(Automaton&);
    Automaton* convert();
    
private:
    Automaton& original;
    std::map<std::string, std::pair<State*, std::bitset<32> > > originalStates;
    State* newStates[128];
    int totalStates;
    
    void populateStates();
    void populateTransitions();
};

#endif