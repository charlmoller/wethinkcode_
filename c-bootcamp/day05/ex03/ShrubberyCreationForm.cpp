
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::action(void) const {

    std::string fname(getTarget() + "_shrubbery");

    std::ofstream ofile(fname.c_str());

    ofile << "              v .   ._, |_  .,\n";
    ofile << "           `-._\\/  .  \\ /    |/_\n";
    ofile << "               \\  _\\, y | \\//\n";
    ofile << "         _\\_.___\\, \\/ -.\\||\n";
    ofile << "           `7-,--.`._||  / / ,\n";
    ofile << "           /'     `-. `./ / |/_.'\n";
    ofile << "                     |    |//\n";
    ofile << "                     |_    /\n";
    ofile << "                     |-   |\n";
    ofile << "     Boabab          |   =|\n";
    ofile << "                     |    |\n";
    ofile << "--------------------/ ,  . \\--------._\n";

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) :
    Form("ShrubberyCreationForm", 0, 145, 137) {
    setTarget(t);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& cc ) {
    Form::operator=(cc);
    return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& cc ) { *this = cc; }