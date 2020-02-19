
#include "Bureaucrat.hpp"

const int Bureaucrat::highestGrade = 1;
const int Bureaucrat::lowestGrade = 150;

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade Too High Exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too Low Exception";
}

void Bureaucrat::checkGrade(void) {
    if (grade < highestGrade)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > lowestGrade)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incrementGrade(void) {
    grade--;
    checkGrade();
}

void Bureaucrat::decrementGrade(void) {
    grade++;
    checkGrade();
}

int Bureaucrat::getGrade(void) const {
    return grade;
}

const std::string& Bureaucrat::getName(void) const {
    return name;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& cc ) {
    grade = cc.grade;
    return *this;
}
Bureaucrat::Bureaucrat( const Bureaucrat& cc ) { *this = cc; }
Bureaucrat::Bureaucrat(  std::string n, int g ) : name(n), grade(g) {}
Bureaucrat::Bureaucrat() : name(""), grade(150) {}
Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& cc) {
    std::string s = ", bureaucrat grade ";
    return out << cc.getName() << s << cc.getGrade() << ".\n";
}