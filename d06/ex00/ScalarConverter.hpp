#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <string>

class ScalarConverter{

public:

	ScalarConverter(std::string const & src);
	virtual	~ScalarConverter(void);

	int		getPrecision(void) const; 
	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;
	bool	getUnset(void) const;
	bool	getPseudo(void) const;

private:

	ScalarConverter(void);
	ScalarConverter(ScalarConverter const & src);
	virtual ScalarConverter &	operator=(ScalarConverter const & rhs);

	char	_c;
	int		_i;
	float	_f;
	double	_d;
	bool	_unset;
	bool	_pseudo;


	void	_setPrecision(std::string const & src);
	int		_precision;

	void	_isPseudoLiteral(std::string const & src);

	bool	_isChar(std::string const & src);
	bool	_isFloat(std::string const & src);
	bool	_isDouble(std::string const & src);
	bool	_isInt(std::string const & src);
	bool	_isUnset(std::string const & src);

	typedef	bool	(ScalarConverter::*Type)(std::string const &);
	
	Type	_isType[5];

	void	CastAll(char c);
	void	CastAll(int i);
	void	CastAll(float f);
	void	CastAll(double d);

};

std::ostream &	operator<<(std::ostream & o, ScalarConverter const & rhs);

#endif
