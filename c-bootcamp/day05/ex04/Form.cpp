
#include "Form.hpp"
#include "Bureaucrat.hpp"

const int Form::highestGrade = 1;
const int Form::lowestGrade = 150;

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade Too High Exception";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade Too Low Exception";
}

void Form::checkGrade(void) {
    if (execGrade < highestGrade || signGrade < highestGrade)
        throw Form::GradeTooHighException();
    else if (execGrade > lowestGrade || signGrade > lowestGrade)
        throw Form::GradeTooLowException();
}

void Form::beSigned( const Bureaucrat& b ) {
    if (b.getGrade() <= signGrade){
        sig = 1;
    } else throw Form::GradeTooLowException();
}

void Form::execute( const Bureaucrat& b ) const {
    if (b.getGrade() > execGrade)
        throw Form::GradeTooLowException();
    if (sig == 1) {        
        action();
    } else {
        std::cout << "Cannot executed unsigned form!\n";
    }
}

int Form::getSigngrade(void) const {
    return signGrade;
}

int Form::getExecgrade(void) const {
    return execGrade;
}

int Form::isSigned(void) const {
    return sig;
}

const std::string& Form::getName(void) const {
    return name;
}

const std::string& Form::getTarget(void) const {
    return target;
}

void Form::setTarget(std::string t) {
    target = t;
}


Form& Form::operator=( const Form& cc ) {
    sig = cc.sig;
    execGrade = cc.execGrade;
    signGrade = cc.signGrade;
    return *this;
}
Form::Form( const Form& cc ) { *this = cc; }
Form::Form(  std::string n, int s, int ex, int si ) :
    name(n), sig(s), execGrade(ex), signGrade(si) {}
Form::Form() : name(""), sig(0), execGrade(150), signGrade(150) {}
Form::~Form() {}

std::ostream& operator<<(std::ostream& out, Form const& cc) {
    out  << "Form " << cc.getName() << " [Exec:" << cc.getExecgrade();
    out << " Sign:" << cc.getSigngrade() << "] ";
    return out << (cc.isSigned() ? "is signed" : "is not signed");
}