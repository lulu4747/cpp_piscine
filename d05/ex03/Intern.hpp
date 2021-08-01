#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{

public:

	Intern(void);
	virtual ~Intern(void);

	Form *	makeForm(std::string const & name, std::string const & target);

private:

	Intern(Intern const & src);

	Intern &	operator=(Intern const & rhs);

	typedef Form* 	(Intern::*ConstructorPointer)(std::string const &);

	std::string			_type[3];
	ConstructorPointer	_make[3];

	Form*	makePresidentialPardonForm(std::string const & target);
	Form*	makeRobotomyRequestForm(std::string const & target);
	Form*	makeShrubberyCreationForm(std::string const & target);
};

#endif
