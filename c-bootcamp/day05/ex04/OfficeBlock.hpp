#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include <exception>
#include <string>
#include "intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{

    Intern* intern;
    Bureaucrat* signer;
    Bureaucrat* executor;

public:
    
    class BureaucracyBrokenException;

    void setIntern( Intern& );
    void setSigner( Bureaucrat& );
    void setExecutor( Bureaucrat& );
    void doBureaucracy( std::string, std::string );
    OfficeBlock( Intern*, Bureaucrat*, Bureaucrat* );
    OfficeBlock& operator=( const OfficeBlock& );
    OfficeBlock( const OfficeBlock& );
    OfficeBlock();
    ~OfficeBlock();

};

class OfficeBlock::BureaucracyBrokenException : public std::exception
{
public:
    virtual const char *what() const throw();
};

#endif // OFFICEBLOCK_HPP