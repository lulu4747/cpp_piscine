#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form{

public:

	Form(std::string const & name, int sign, int exec);
	Form(Form const & src);
	virtual	~Form(void);

	Form &	operator=(Form const & rhs);

	std::string const	getName(void) const;
	int 	getGradeToSign(void) const;
	int 	getGradeToExecute(void) const;
	bool	getSignature(void) const;

	void	beSigned(Bureaucrat const & bureaucrat);

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

	Form(void);

	std::string const	_name;
	int const			_grade_to_sign;
	int const			_grade_to_execute;

	bool		_signature;

};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);

#endif
