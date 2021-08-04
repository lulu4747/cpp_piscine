#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <string>

class Literal{

public:

	Literal(std::string const & src);
	virtual	~Literal(void);

	int		getPrecision(void) const; 
	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;
	bool	getUnset(void) const;

private:

	Literal(void);
	Literal(Literal const & src);
	virtual Literal &	operator=(Literal const & rhs);

	char	_c;
	int		_i;
	float	_f;
	double	_d;
	bool	_unset;


	void	_setPrecision(std::string const & src);
	int		_precision;

	bool	isFloat(std::string const & src);
	bool	isDouble(std::string const & src);
	bool	isInt(std::string const & src);
	bool	isUnset(std::string const & src);

	typedef	bool	(Literal::*Type)(std::string const &);
	
	Type	_isType[4];

	void	CastAll(char c);
	void	CastAll(int i);
	void	CastAll(float f);
	void	CastAll(double d);

};

std::ostream &	operator<<(std::ostream & o, Literal const & rhs);

#endif
