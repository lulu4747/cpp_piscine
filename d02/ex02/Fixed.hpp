#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed{

public:

	Fixed(void);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed(void);
	Fixed(Fixed const & src);

	Fixed &		operator=(Fixed const & rhs);
	
	bool		operator>(Fixed const & rhs) const;
	bool		operator<(Fixed const & rhs) const;
	bool		operator>=(Fixed const & rhs) const;
	bool		operator<=(Fixed const & rhs) const;
	bool		operator==(Fixed const & rhs) const;
	bool		operator!=(Fixed const & rhs) const;

	Fixed		operator+(Fixed const & rhs) const;
	Fixed		operator-(Fixed const & rhs) const;
	Fixed		operator*(Fixed const & rhs) const;
	Fixed		operator/(Fixed const & rhs) const;

	Fixed &		operator++();
	Fixed &		operator--();
	Fixed		operator++(int);
	Fixed		operator--(int);

	static const Fixed &	min(Fixed const & lhs, Fixed const & rhs)
	{
		if (lhs.getRawBits() < rhs.getRawBits())
			return lhs;
		return rhs;
	}

	static const Fixed &	max(Fixed const & lhs, Fixed const & rhs)
	{
		if (lhs.getRawBits() > rhs.getRawBits())
			return lhs;
		return rhs;
	}

	int			getRawBits(void) const;
	float		toFloat(void) const;
	int			toInt(void) const;
	void		setRawBits(int const raw);

private:

	int					_rawbits;
	static const int	_fracbits = 8;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif
