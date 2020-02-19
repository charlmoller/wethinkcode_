
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::action(void) const {
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox.\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string t) :
    Form("PresidentialPardonForm", 0, 25, 5) {
    setTarget(t);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& cc ) {
    Form::operator=(cc);
    return *this;
}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& cc ) { *this = cc; }