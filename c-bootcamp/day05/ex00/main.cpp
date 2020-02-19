
#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{

    try {
        Bureaucrat test1 = Bureaucrat("testhigh", 1);
        test1.incrementGrade();
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        Bureaucrat test2 = Bureaucrat("testlow", 150);
        test2.decrementGrade();
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}