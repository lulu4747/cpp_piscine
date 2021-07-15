#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void):_rawbits(0){

	return ;
}

Fixed::Fixed(const int n){

	this->_rawbits = n << Fixed::_fracbits;
	return ;
}

Fixed::Fixed(const float n){

	this->_rawbits = roundf(n * (1 << Fixed::_fracbits));
	return ;
}

Fixed::~Fixed(void){

	return ;
}

Fixed::Fixed(Fixed const & src){

	*this = src;
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs){

	if (this != &rhs)
		this->_rawbits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const{

	return this->_rawbits;
}

float	Fixed::toFloat(void) const{

	return ((float)(this->_rawbits) / (1 << Fixed::_fracbits));
}

int	Fixed::toInt(void) const{

	return this->_rawbits >> Fixed::_fracbits;
}

void	Fixed::setRawBits(int const raw){

	this->_rawbits = raw;
	return ;
}

std::ostream &	operator<<(std::ostream & o, Fixed const &rhs){

	o << rhs.toFloat();
	return o;
}