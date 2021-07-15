#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point{

public:

	Point(void);
	~Point(void);
	Point(Point const & src);
	Point(Fixed const & x, Fixed const & y);
	Point(float const & x, float const & y);

	Point &	operator=(Point const & rhs);

	Fixed const &	getX(void) const;
	Fixed const &	getY(void) const;

private:

	Fixed const	_x;
	Fixed const	_y;

};

#endif
