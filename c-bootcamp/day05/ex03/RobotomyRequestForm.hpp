#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{

public:

    void action(void) const;
    RobotomyRequestForm( const RobotomyRequestForm& cc );
    RobotomyRequestForm& operator=( const RobotomyRequestForm& cc );
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    
};

#endif // ROBOTOMY_REQUEST_FORM_HPP
