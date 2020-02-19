#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{

public:

    void action(void) const;
    ShrubberyCreationForm( const ShrubberyCreationForm& cc );
    ShrubberyCreationForm& operator=( const ShrubberyCreationForm& cc );
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    
};

#endif // SHRUBBERY_CREATION_FORM_HPP
