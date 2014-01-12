#include <iostream>
#include <string>

#include "state.h"
#include "automaton.h"
#include "converter.h"

int main()
{
    std::string file;
    std::cout << "Enter input file:";
    std::cin >> file;
    
	Automaton nfa(file);
    std::cout << "Loaded NFA" << std::endl << "-------------------------" << std::endl;
    std::cout << nfa.print() << std::endl;
    
    Converter converter(nfa);
    Automaton converted_dfa = *converter.convert();
	
    std::cout << std::endl << "Converted DFA" << std::endl << "-------------------------";
	std::cout << converted_dfa.print() << std::endl;
    
    std::string input;
    std::cout << "Control-C to exit" << std::endl;
    
    while (true)
    {
        std::cout << std::endl << "Please enter input string:";
        std::cin >> input;
        bool result = converted_dfa.decideString(input);
        
        if (result == true)
        {
            std::cout << "Automaton accepted the string" << std::endl;
        }
        else
        {
            std::cout << "Automaton rejected the string" << std::endl;
        }
    }
    
	
}