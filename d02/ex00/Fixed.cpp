#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void):_rawbits(0){

	std::cout << "Default constructor called" << std::endl;
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

void	Fixed::setRawwBits(int const raw){

	this->_rawbits = raw;
	return ;
}