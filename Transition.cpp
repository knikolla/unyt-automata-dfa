//
//  Transition.cpp
//  unyt-automata-dfa
//
//  Created by Kristi Nikolla on 12/28/13.
//
//

#include "Transition.h"

Transition::Transition(char symbol, State* origin, State* destination)
{
    this->symbol = symbol;
    this->origin = origin;
    this->destination = destination;
}

char Transition::getSymbol()
{
    return this->symbol;
}

State* Transition::getOrigin()
{
    return this->origin;
}

State* Transition::getDestination()
{
    return this->destination;
}