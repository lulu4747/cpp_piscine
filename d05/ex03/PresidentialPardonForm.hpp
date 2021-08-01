#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form{

public:

	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	virtual	~PresidentialPardonForm(void);

	PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;

private:

	PresidentialPardonForm(void);

	std::string	_target;

};

#endif
