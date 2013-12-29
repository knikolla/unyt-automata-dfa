#ifndef __unyt_automata_dfa__State__
#define __unyt_automata_dfa__State__

#include <string>
#include <vector>

class Transition;

class State
{
    private:    
    std::string* name;
    std::vector<Transition*>* transitions[100];
    bool accepting;
    
    public:
    State(std::string* name);
    std::string* getName();
    void addTransition(Transition* transition);
    std::vector<Transition*>* getTransitions(char symbol);
    bool isAccepting();
    void setAccepting(bool accepting);
};


#endif