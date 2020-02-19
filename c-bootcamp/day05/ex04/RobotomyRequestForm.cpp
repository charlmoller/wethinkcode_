
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::action(void) const {
    if (rand() % 2){
        std::cout << getTarget() << " has been robotomized successfully.\n";
    }
    else {
        std::cout << getTarget() << " robotomization failure.\n";
    }
}

RobotomyRequestForm::RobotomyRequestForm(std::string t) :
    Form("RobotomyRequestForm", 0, 72, 45) {
    srand (time(NULL));
    setTarget(t);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& cc ) {
    Form::operator=(cc);
    return *this;
}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& cc ) { *this = cc; }