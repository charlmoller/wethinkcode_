

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Form* Intern::makeForm(std::string f, std::string t) {
    Form* ret = 0;
    if (f == "robotomy request") {
        ret = new RobotomyRequestForm(t);
    } else if (f == "shrubbery creation") {
        ret = new ShrubberyCreationForm(t);
    } else if (f == "presidential pardon") {
        ret = new PresidentialPardonForm(t);
    } else {
        std::cout << "Could not create form " << f << "\n";
        return ret;
    }
    std::cout << "Intern creates " << f << "\n";
    return ret;
}

Intern& Intern::operator=( const Intern& ){
    return *this;
}
Intern::Intern( const Intern& cc ){ *this = cc; }
Intern::Intern(){}
Intern::~Intern(){}