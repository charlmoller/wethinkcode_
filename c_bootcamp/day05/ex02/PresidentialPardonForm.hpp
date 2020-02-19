#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{

public:

    void action(void) const;
    PresidentialPardonForm( const PresidentialPardonForm& cc );
    PresidentialPardonForm& operator=( const PresidentialPardonForm& cc );
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
