#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{

    static const int highestGrade;
    static const int lowestGrade;

    const std::string name;
    int grade;

public:

    void checkGrade(void);
    void incrementGrade(void);
    void decrementGrade(void);
    int getGrade(void) const;
    const std::string& getName(void) const;

    class GradeTooHighException;
    class GradeTooLowException;

    Bureaucrat( std::string n, int g );
    Bureaucrat( const Bureaucrat& cc );
    Bureaucrat& operator=( const Bureaucrat& cc );
	Bureaucrat();
	~Bureaucrat();
	
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& cc );

class Bureaucrat::GradeTooHighException : public std::exception
{
public:
    virtual const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
public:
    virtual const char* what() const throw();
};

#endif // BUREAUCRAT_HPP
