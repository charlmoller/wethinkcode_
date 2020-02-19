
#include "Form.hpp"
#include "OfficeBlock.hpp"

void OfficeBlock::setIntern( Intern& i ) {
    intern = &i;
}

void OfficeBlock::setSigner( Bureaucrat& s ) {
    signer = &s;
}

void OfficeBlock::setExecutor( Bureaucrat& e ) {
    executor = &e;
}

void OfficeBlock::doBureaucracy( std::string f, std::string t )
{
    Form *form;

    form = intern->makeForm(f, t);
    if (intern && signer && executor && form) {
        signer->signForm(*form);
        executor->executeForm(*form);
    } else throw BureaucracyBrokenException();
}

OfficeBlock& OfficeBlock::operator=( const OfficeBlock& cc ) {
    intern = cc.intern;
    signer = cc.signer;
    executor = cc.executor;
    return *this;
}
OfficeBlock::OfficeBlock( const OfficeBlock& cc ) {
    *this = cc;
}
OfficeBlock::OfficeBlock() :
    intern(0), signer(0), executor(0) {}
OfficeBlock::OfficeBlock(Intern* in, Bureaucrat* si, Bureaucrat* ex) :
    intern(in), signer(si), executor(ex) {}
OfficeBlock::~OfficeBlock(){}

const char* OfficeBlock::BureaucracyBrokenException::what() const throw() {
    return ("Chain of bureaucracy is broken.");
}
