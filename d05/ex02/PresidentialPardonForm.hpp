#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form{

public:

	PresidentialPardonForm(std::string const & name);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	virtual	~PresidentialPardonForm(void);

	PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);

	void	execute(Bureaucrat const & bureaucrat, std::string const & target) const;

private:

	PresidentialPardonForm(void);

};

#endif
