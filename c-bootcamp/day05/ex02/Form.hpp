#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include <stdlib.h>
#include <time.h>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>

class Form
{

    const std::string name;
    int sig;
    int execGrade;
    int signGrade;
    std::string target;

    static const int highestGrade;
    static const int lowestGrade;

public:

    virtual void action( void ) const = 0;
    void execute( Bureaucrat const & executor ) const;
    void checkGrade(void);
    void beSigned( const Bureaucrat& b );
    int getExecgrade(void) const;
    int getSigngrade(void) const;
    int isSigned(void) const; 
    const std::string& getName(void) const;
    const std::string& getTarget(void) const;
    void setTarget(std::string);

    class GradeTooHighException;
    class GradeTooLowException;

    Form( std::string n, int s, int ex, int si );
    Form( const Form& cc );
    Form& operator=( const Form& cc );
	Form();
	~Form();
	
};

std::ostream& operator<<(std::ostream& out, Form const& cc );

class Form::GradeTooHighException : public std::exception
{
public:
    virtual const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
public:
    virtual const char* what() const throw();
};

#endif // FORM_HPP
