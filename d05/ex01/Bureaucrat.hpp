#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include "Form.hpp"

class Bureaucrat{

public:

	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(Bureaucrat const & src);
	virtual	~Bureaucrat(void);

	virtual Bureaucrat &	operator=(Bureaucrat const & rhs);
	
	std::string	const &	getName(void) const;
	int					getGrade(void) const;

	void	upgrade(void);
	void	downgrade(void);
	void	signForm(Form & form);

	class GradeTooHighException : public std::exception{
	public:
		virtual const char *	what() const throw(){
			return ("Grade too high");
		}
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char *	what() const throw(){
			return ("Grade too low");
		}
	};

private:

	Bureaucrat(void);

	std::string const	_name;
	int					_grade;

};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
