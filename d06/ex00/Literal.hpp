#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <string>

class Literal{

public:

	Literal(void);
	Literal(Literal const & src);
	Literal(std::string const & src);
	virtual	~Literal(void);

	virtual Literal &	operator=(Literal const & rhs);

	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

private:

	char	_c;
	int		_i;
	float	_f;
	double	_d;

	bool	isPseudo(std::string const & src);
	bool	isChar(std::string const & src);
	bool	isInt(std::string const & src);
	bool	isFloat(std::string const & src);
	bool	isDouble(std::string const & src);

	typedef	bool	(Literal::*Type)(std::string const &);
	
	Type const	_isType[5] = 
	{
		&Literal::isPseudo,
		&Literal::isChar,
		&Literal::isInt,
		&Literal::isFloat,
		&Literal::isDouble
	};

	void	CastAll(char c);
	void	CastAll(int i);
	void	CastAll(float f);
	void	CastAll(double d);

};

std::ostream &	operator<<(std::ostream & o, Literal const & rhs);

#endif
