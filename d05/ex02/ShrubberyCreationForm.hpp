#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form{

public:

	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	virtual	~ShrubberyCreationForm(void);

	ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;

private:

	ShrubberyCreationForm(void);

};

#endif
