#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{

public:

    Form* makeForm(std::string, std::string);
    Intern( const Intern& );
    Intern& operator=( const Intern& );
    Intern();
    ~Intern();
    
};

#endif // INTERN_HPP
