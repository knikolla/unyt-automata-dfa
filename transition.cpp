#include "transition.h"

#include "state.h"

Transition::Transition(char symbol, State& o, State& d) : origin(o), destination(d)
{
    this->symbol = symbol;
}

char Transition::getSymbol()
{
    return this->symbol;
}

State& Transition::getOrigin()
{
    return this->origin;
}

State& Transition::getDestination()
{
    return this->destination;
}

std::string Transition::print()
{
	return std::string("Origin: " + this->origin.getName() 
		+ ", Destination: " + this->destination.getName()
		+ ", Symbol: " + this->symbol + "\n");
}