#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form{

public:

	RobotomyRequestForm(std::string const & target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	virtual	~RobotomyRequestForm(void);

	RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;

private:

	RobotomyRequestForm(void);

};

#endif