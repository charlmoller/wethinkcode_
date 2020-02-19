
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    PresidentialPardonForm testForm1 = PresidentialPardonForm("LOLOL");
    Bureaucrat test1 = Bureaucrat("Bureaucrat1", 149);
    test1.signForm(testForm1);

    PresidentialPardonForm testForm2 = PresidentialPardonForm("LOLOL");
    Bureaucrat test2 = Bureaucrat("Bureaucrat2", 90);
    test2.signForm(testForm2);
    test2.executeForm(testForm2);

    PresidentialPardonForm testForm3 = PresidentialPardonForm("LOLOL");
    Bureaucrat test3 = Bureaucrat("Bureaucrat3", 1);
    test3.signForm(testForm3);
    test3.executeForm(testForm3);

    ShrubberyCreationForm testForm4 = ShrubberyCreationForm("LOLOL");
    Bureaucrat test4 = Bureaucrat("Bureaucrat4", 1);
    test4.signForm(testForm4);
    test4.executeForm(testForm4);

    RobotomyRequestForm testForm5 = RobotomyRequestForm("LOLOL");
    Bureaucrat test5 = Bureaucrat("Bureaucrat5", 1);
    test5.signForm(testForm5);
    test5.executeForm(testForm5);

}