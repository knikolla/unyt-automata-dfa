#include "automaton.h"

#include <string>
#include <fstream>

#include "state.h"
#include "transition.h"
#include "utilities.h"

Automaton::Automaton()
{
    
}

Automaton::Automaton(std::string text_location)
{
    std::ifstream file(text_location);
    if (file.is_open())
    {
        std::string line;
        std::string delimiter = " ";
        
        // first line is list of states
        getline(file,line);
        std::vector<std::string> state_vector = utilities::split(line, delimiter);
        for (std::string s_name : state_vector)
        {
            addState(*new State(s_name));
        }
        
        // second line is alphabet
        getline(file,line);
        for (char symbol : line)
        {
            if (symbol != ' ') addSymbol(symbol);
        }
        
        // third line is list of accepting states
        getline(file, line);
        state_vector = utilities::split(line, delimiter);
        for (std::string accepting_name : state_vector)
        {
            getState(accepting_name)->setAccepting(true);
        }
        
        // fourth line and forward, list of transitions
        std::vector<std::string> transition_vector;
        while (getline(file, line))
        {
            transition_vector = utilities::split(line, " ");
            
            char symbol = transition_vector[1][0];
            for (int i = 2; i < transition_vector.size(); i++)
            {
                addTransition(symbol, transition_vector.front(), transition_vector[i]);
            }
        }
    }
    else{
        std::cout << "Unable to open file" << std::endl;
        std::abort();
    }
}

void Automaton::addSymbol(char s)
{
    alphabet.push_back(s);
}

const std::vector<char>& Automaton::getAlphabet()
{
    return alphabet;
}

void Automaton::addState(State& state)
{
	if (states.empty() == true)
	{
		startState = &state;
	}

	states[state.getName()] = &state;
}

State* Automaton::getState(std::string name)
{
	return states[name];
}

const std::map<std::string, State*>& Automaton::getStates()
{
    return states;
}

void Automaton::setStartState(State* start)
{
    this->startState = start;
}

void Automaton::addTransition(char s, std::string o, std::string d)
{
	State* origin = states[o];
	State* destination = states[d];
	origin->addTransition(new Transition(s, *origin, *destination));
}

bool Automaton::decideString(std::string input)
{
	currentState = startState;

	for (int i = 0; i < input.size(); i++)
	{
		Transition* t = currentState->getTransitions(input.at(i))->front();
		currentState = &t->getDestination();
        
        if (currentState == NULL)
        {
            std::cout << "Why am i null??";
            return false;
        }
	}
    
	if (currentState->isAccepting() == true)
    {
		return true;
	}
	else
    {
        return false;
    }
}

std::string Automaton::print()
{
	std::string result = std::string("");
	for (auto s : states)
	{
		result.append(s.second->print());
	}
	return result;
}

