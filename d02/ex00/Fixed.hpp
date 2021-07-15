#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed{

public:

	Fixed(void);
	~Fixed(void);
	Fixed(Fixed const & src);

	Fixed &		operator=(Fixed const & rhs);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);

private:

	int					_rawbits;
	static const int	_fracbits = 8;

};

#endif
