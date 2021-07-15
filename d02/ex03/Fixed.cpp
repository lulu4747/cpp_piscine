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

bool	Fixed::operator>(Fixed const & rhs) const{

	return this->_rawbits > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const & rhs) const{

	return this->_rawbits < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs) const{

	return this->_rawbits >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const & rhs) const{

	return this->_rawbits <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const & rhs) const{

	return this->_rawbits == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs) const{

	return this->_rawbits != rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const & rhs) const{

	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const{

	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const{

	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const{

	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++(){

	this->_rawbits = this->_rawbits + 1;
	return *this;
}

Fixed &	Fixed::operator--(){

	this->_rawbits = this->_rawbits - 1;
	return *this;
}

Fixed	Fixed::operator++(int){

	Fixed	copy = Fixed(*this);

	this->_rawbits = this->_rawbits + 1;
	return copy;
}

Fixed	Fixed::operator--(int){

	Fixed	copy = Fixed(*this);

	this->_rawbits = this->_rawbits - 1;
	return copy;
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