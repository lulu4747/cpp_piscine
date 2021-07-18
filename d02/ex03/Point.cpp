#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void):_x(Fixed(0)),_y(Fixed(0)){

	return ;
}

Point::~Point(void){

	return ;
}

Point::Point(Point const & src):_x(src.getX()),_y(src.getY()){

	return ;
}

Point::Point(Fixed const & x, Fixed const & y):_x(x), _y(y){

	return ;
}

Point::Point(float const & x, float const & y):_x(Fixed(x)), _y(Fixed(y)){

	return ;
}

Point &	Point::operator=(Point const & rhs){

	(void)rhs;
	return *this;
}

Fixed	Point::getX(void) const{

	return this->_x;
}

Fixed	Point::getY(void) const{

	return this->_y;
}