#include "State.h"
#include "Transition.h"

State::State(std::string& n) : name(n)
{
	for (int i = 0; i < MAX_T; i++)
	{
		this->transitions[i] = new std::vector<Transition*>();
	}
}

std::string& State::getName()
{
    return this->name;
}

void State::addTransition(Transition* t)
{
	this->transitions[t->getSymbol()]->push_back(t);
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

void State::setAccepting(bool a)
{
    this->accepting = a;
}

std::string State::print()
{
	std::string result = std::string("STATE - Name: " + this->getName() 
		+ "\n" + "Transitions:" + "\n");
	for (auto a : this->transitions)
	{
		for (auto t : *a)
		{
			result.append(t->print());
		}
	}
	result.append("\n");
	return result;
}