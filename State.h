#ifndef __unyt_automata_dfa__State__
#define __unyt_automata_dfa__State__

#include <string>
#include <vector>

#define MAX_T 256

class Transition;

class State
{
    public:
		State(std::string);
		std::string getName();
		void addTransition(Transition*);
		std::vector<Transition*>* getTransitions(char);
		bool isAccepting();
		void setAccepting(bool);
		std::string print();

	private:
		std::string name;
		std::vector<Transition*>* transitions[MAX_T];
		bool accepting;
};


#endif