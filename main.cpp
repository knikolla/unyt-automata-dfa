#include <iostream>
#include <string>

#include "State.h"

int main()
{
    State* h = new State(new std::string("A"));
    std::cout << *h->getName() << "\n";
}