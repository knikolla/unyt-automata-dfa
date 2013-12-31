#include "converter.h"

#include "automaton.h"

Converter::Converter(Automaton& o) : original(o)
{
    
}

Automaton Converter::convert()
{
    Automaton result;
    
    return result;
}

void Converter::populateOriginalStates()
{
    static int offset = 1;
    
    for (auto s : this->original.getStates())
    {
        this->originalStates[s.first] = std::pair<State*, int>(s.second, offset);
        this->newStates[offset] = s.second;
        offset*=2;
    }
}
