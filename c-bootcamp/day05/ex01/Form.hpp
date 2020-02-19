#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include <exception>
#include <iostream>
#include <string>

class Form
{

    static const int highestGrade;
    static const int lowestGrade;

    const std::string name;
    int sig;
    int execGrade;
    int signGrade;

public:


    void checkGrade(void);
    void beSigned( const Bureaucrat& b );
    int getExecgrade(void) const;
    int getSigngrade(void) const;
    int isSigned(void) const; 
    const std::string& getName(void) const;

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
