#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form{

public:

	RobotomyRequestForm(std::string const & name);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	virtual	~RobotomyRequestForm(void);

	RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);

	void	execute(Bureaucrat const & bureaucrat, std::string const & target) const;

private:

	RobotomyRequestForm(void);

};

#endif