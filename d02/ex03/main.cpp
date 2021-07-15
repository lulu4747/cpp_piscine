#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point	pts[4];
	char	abcn[5] = "abcn";
	float	x;
	float	y;

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "Coordonate for " << abcn[i] << " point as float: " << std::endl << "x = ";
		std::cin >> x;
		std::cin.get();
		std::cout << "y = ";
		std::cin >> y;
		std::cin.get();
		pts[i] = Point(Fixed(x), Fixed(y));
	}
	std::cout << std::boolalpha << "bsp return is : " << bsp(pts[0], pts[1], pts[2], pts[3]) << std::endl;
	return 0;
}
