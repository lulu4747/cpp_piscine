#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target):Form(target, "ShrubberyCreationForm", 145, 137){

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):Form(src.getTarget(), src.getName(), 145, 137){

	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){

	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){

	this->Form::operator=(rhs);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

	Form::execute(executor);

	std::string		tmp(this->getTarget() + "_shrubbery");
	std::ofstream	os(tmp.c_str());

	os << "             .o00o" << std::endl
		<< "           o000000oo" << std::endl
		<< "           o000000oo" << std::endl
		<< "          00000000000o" << std::endl
		<< "         00000000000000" << std::endl
		<< "      oooooo  00000000  o88o" << std::endl
		<< "   ooOOOOOOOoo  ```''  888888" << std::endl
		<< " OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl
		<< "oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl
		<< "OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl
		<< " OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl
		<< "   OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl
		<< "     OO:F_P:O `QQQ/  /Q'" << std::endl
		<< "        \\\\. \\ |  // |" << std::endl
		<< "        d\\ \\\\\\|_////" << std::endl
		<< "        qP| \\ _' `|Ob" << std::endl
		<< "           \\  / \\  \\Op" << std::endl
		<< "           |  | O| |" << std::endl
		<< "   _       /\\. \\_/ /\\" << std::endl
		<< "    `---__/|_\\   //|  __" << std::endl
		<< "          `-'  `-'`-'-'"
	<< std::endl;

	os.close();

	return ;
}
