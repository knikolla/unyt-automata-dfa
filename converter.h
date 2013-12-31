#ifndef __unyt_automata_dfa__converter__
#define __unyt_automata_dfa__converter__

#include <iostream>
#include <map>

#include "state.h"
#include "automaton.h"

class Converter
{
    
public:
    Converter(Automaton&);
    Automaton convert();
    
private:
    Automaton& original;
    std::map<std::string, std::pair<State*, int> > originalStates;
    State* newStates[];
    
    void populateOriginalStates();
};

#endif