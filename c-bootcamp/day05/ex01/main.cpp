
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form testForm1 = Form("Form2", 0, 80, 100);
    Bureaucrat test1 = Bureaucrat("Bureaucrat1", 70);
    test1.signForm(testForm1);
    std::cout << "\n";

    try {
        Form testForm2 = Form("Form1", 0, 80, 100);
        Bureaucrat test2 = Bureaucrat("Bureaucrat2", 120);
        test2.signForm(testForm2);
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}