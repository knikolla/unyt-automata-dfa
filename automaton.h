#ifndef __unyt_automata_dfa__Automaton__
#define __unyt_automata_dfa__Automaton__

#include <string>
#include <vector>
#include <map>

class State;
class Transition;

class Automaton
{
public:
    Automaton();
    Automaton(std::string);
    void addSymbol(char);
    const std::vector<char>& getAlphabet();
    void addState(State&);
    State* getState(std::string);
    const std::map<std::string, State*>& getStates();
    void setStartState(State*);
    void addTransition(char symbol, std::string, std::string);
    bool decideString(std::string);
    std::string print();

private:
    std::map<std::string, State*> states;
    std::vector<char> alphabet;
    State* startState;
    State* currentState;
};

#endif