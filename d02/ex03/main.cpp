#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	std::cout << std::boolalpha << "bsp return for : " << std::endl
		<< "a(0, 0), b(0, 5), c(5. 0), point(1, 1): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 1)) << std::endl
		<< "a(0, 0), b(0, 5), c(5. 0), point(0, 5): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 5)) << std::endl
		<< "a(0, 0), b(0, 5), c(5. 0), point(0, 3): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3)) << std::endl
		<< "a(0, 0), b(0, 5), c(5. 0), point(0, 0): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0)) << std::endl
		<< "a(0, 0), b(0, 5), c(5. 0), point(0.1, 0.01): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1, 0.01)) << std::endl;
	return 0;
}
