//
//  State.cpp
//  unyt-automata-dfa
//
//  Created by Kristi Nikolla on 12/28/13.
//
//

#include "State.h"
#include "Transition.h"

State::State(std::string* name)
{
    this->name = name;
}

std::string* State::getName()
{
    return this->name;
}

void State::addTransition(Transition* transition)
{
    int position = (int) transition->getSymbol();
    this->transitions[position]->push_back(transition);
}

std::vector<Transition*>* State::getTransitions(char symbol)
{
    int position = (int) symbol;
    return this->transitions[position];
}

bool State::isAccepting()
{
    return this->accepting;
}

void State::setAccepting(bool accepting)
{
    this->accepting = accepting;
}