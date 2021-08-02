#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <string>

class Literal{

public:

	Literal(std::string const & src);
	virtual	~Literal(void);


	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

private:

	Literal(void);
	Literal(Literal const & src);
	virtual Literal &	operator=(Literal const & rhs);

	char	_c;
	int		_i;
	float	_f;
	double	_d;
	bool	_unset;

	bool	isPseudo(std::string const & src);
	bool	isChar(std::string const & src);
	bool	isInt(std::string const & src);
	bool	isFloat(std::string const & src);
	bool	isDouble(std::string const & src);
	bool	isUnset(std::string const & src);

	typedef	bool	(Literal::*Type)(std::string const &);
	
	Type const	_isType[6] = 
	{
		&Literal::isPseudo,
		&Literal::isChar,
		&Literal::isInt,
		&Literal::isFloat,
		&Literal::isDouble,
		&Literal::isUnset
	};

	void	CastAll(char c);
	void	CastAll(int i);
	void	CastAll(float f);
	void	CastAll(double d);

	static float const	inff = std::numeric_limits<float>::infinity();
	static float const	nanf = std::numeric_limits<float>::quiet_NaN();
	static double const	inf = std::numeric_limits<double>::infinity();
	static double const	nan = std::numeric_limits<double>::quiet_NaN();

};

std::ostream &	operator<<(std::ostream & o, Literal const & rhs);

#endif
