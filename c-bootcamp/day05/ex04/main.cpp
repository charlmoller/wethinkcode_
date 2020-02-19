
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{
    Intern idiotOne;
    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 1);
    Bureaucrat bob = Bureaucrat("Bobby Bobson", 1);
    OfficeBlock ob1;
    ob1.setIntern(idiotOne);
    ob1.setSigner(bob);
    ob1.setExecutor(hermes);
    try {
        ob1.doBureaucracy("mutant pig termination", "Pigley");
    } catch (OfficeBlock::BureaucracyBrokenException & e) {
        std::cout << e.what() << '\n';
    } catch (std::exception & e) {
        std::cout << e.what() << '\n';
    }

    try {   
        ob1.doBureaucracy("robotomy request", "Pigley");
    } catch (OfficeBlock::BureaucracyBrokenException & e) {
        std::cout << e.what() << '\n';
    } catch (std::exception & e) {
        std::cout << e.what() << '\n';
    }
    try {   
        ob1.doBureaucracy("shrubbery creation", "Pigley");
    } catch (OfficeBlock::BureaucracyBrokenException & e) {
        std::cout << e.what() << '\n';
    } catch (std::exception & e) {
        std::cout << e.what() << '\n';
    }
    try {   
        ob1.doBureaucracy("presidential pardon", "Pigley");
    } catch (OfficeBlock::BureaucracyBrokenException & e) {
        std::cout << e.what() << '\n';
    } catch (std::exception & e) {
        std::cout << e.what() << '\n';
    }
}