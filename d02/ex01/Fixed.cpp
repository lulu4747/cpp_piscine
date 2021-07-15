#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void):_rawbits(0){

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n){

	this->_rawbits = n << Fixed::_fracbits;
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float n){

	this->_rawbits = roundf(n * (1 << Fixed::_fracbits));
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void){

	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src){

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs){

	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_rawbits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const{

	std::cout << "getRawBits member function called" << std::endl;
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