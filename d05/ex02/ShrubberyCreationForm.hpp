#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form{

public:

	ShrubberyCreationForm(std::string const & name);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	virtual	~ShrubberyCreationForm(void);

	ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);

	void	execute(Bureaucrat const & bureaucrat, std::string const & target) const;

private:

	ShrubberyCreationForm(void);

};

#endif
