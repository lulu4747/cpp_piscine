#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	sign[3];

	std::cout << a.getX() << std::endl;
	sign[0] = (((a.getX() - point.getX()) * (b.getY() - point.getY())) - ((a.getY() - point.getY()) * (b.getX() - point.getX())) < 0);
	sign[1] = (((b.getX() - point.getX()) * (c.getY() - point.getY())) - ((b.getY() - point.getY()) * (c.getX() - point.getX())) < 0);
	sign[2] = (((c.getX() - point.getX()) * (a.getY() - point.getY())) - ((c.getY() - point.getY()) * (a.getX() - point.getX())) < 0);
	std::cout << std::boolalpha << sign[0] << " " << sign[1] << " " << sign[2] << std::endl;
	sign[0] = (((0 - 2) * (5 - 2)) - ((0 - 2) * (0 - 2)) < 0);
	sign[1] = (((0 - 2) * (0 - 2)) - ((5 - 2) * (5 - 2)) < 0);
	sign[2] = (((5 - 2) * (0 - 2)) - ((0 - 2) * (0 - 2)) < 0);
	std::cout << std::boolalpha << sign[0] << " " << sign[1] << " " << sign[2] << std::endl;
	//if (sign[0] == sign[1] && sign[1] == sign[2])
	//	return true;
	std::cout << (a.getX() - point.getX()) << std::endl;
	// tout renvoie 0 faut tester operation par operation proprement sinon consequences En fait non toout est deja egal a 0 en rentrant
	return false;
}