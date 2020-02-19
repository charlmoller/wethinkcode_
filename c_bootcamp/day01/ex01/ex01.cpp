
#include <iostream>

std::string *memoryLeak()
{
    std::string *panthere = new std::string("String panthere");
    std::cout << *panthere << std::endl;
    return panthere;
}

int main()
{
    std::string* test = memoryLeak();
    delete test;
    return 0;
}
