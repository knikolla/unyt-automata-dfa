#include "converter.h"

#include "transition.h"

Converter::Converter(Automaton& o) : original(o)
{
    
}

Automaton* Converter::convert()
{
    Automaton* result = new Automaton();
    
    populateStates();
    populateTransitions();
    
    for (int i = 0; i < this->totalStates; i++)
    {
        result->addState(*this->newStates[i]);
    }
    result->setStartState(this->newStates[1]);
    
    return result;
}

void Converter::populateStates()
{
    static std::bitset<32> accessor = 1;
    static std::bitset<32> accepting = 0;
    
    for (auto s : this->original.getStates())
    {
        this->originalStates[s.first] = std::pair<State*, std::bitset<32> >(s.second, accessor);
        
        // if it is an accepting state, add the accessor position
        // to the accepting bitset and set its state to accepting
        if (s.second->isAccepting() == true)
        {
            accepting |= accessor;
        }
        
        accessor <<= 1; //bit shift by 1
    }
    
    this->totalStates = accessor.to_ulong();
    //total number of elements of the powerset is final offset - 1
    for (int i = 0; i < this->totalStates; i++)
    {
        this->newStates[i] = new State(std::bitset<32>(i).to_string());
    
        //compare if any of the accepting bits is set
        std::bitset<32> check = accepting & std::bitset<32>(i);
        if (check.any())
        {
            this->newStates[i]->setAccepting(true);
        }
    }
}

void Converter::populateTransitions()
{
    char alphabet[] = { 'a' };
    for (auto state : this->originalStates)
    {
        std::vector<State*> origins;
        std::bitset<32> bitorigin = this->originalStates[state.first].second;
        // find all the new states containig the original state
        for (int i = 0; i < this->totalStates; i++)
        {
            std::bitset<32> check = bitorigin & std::bitset<32>(i);
            if (check.any())
            {
                origins.push_back(this->newStates[i]);
            }
        }
        
        for (char symbol : alphabet)
        {
            std::bitset<32> bitdest(0);
            for (auto t : *state.second.first->getTransitions(symbol))
            {
                // add the bitset of the transition destination to the overall bitdest
                std::bitset<32> t_dest = this->originalStates[t->getDestination().getName()].second;
                bitdest |= t_dest;
            }
            
            State* destination = this->newStates[bitdest.to_ulong()];
            
            //add to all states that contain the origin
            for (State* state : origins)
            {
                state->addTransition(new Transition(symbol, *state, *destination));
            }
            
        }
    }
}
