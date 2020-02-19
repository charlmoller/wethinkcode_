
#include <string>
#include <iostream>

int main()
{
    std::string *heap = new std::string("HI THIS IS BRAIN");
    std::string stack = "HI THIS IS BRAIN";
    
    std::cout << *heap << "\n";
    std::cout << stack << "\n";
    
    delete heap;
    return 0;
}
