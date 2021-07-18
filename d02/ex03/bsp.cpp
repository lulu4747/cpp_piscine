#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	sign[3];

	sign[0] = (((a.getX() - point.getX()) * (b.getY() - point.getY())) - ((a.getY() - point.getY()) * (b.getX() - point.getX())) < 0);
	sign[1] = (((b.getX() - point.getX()) * (c.getY() - point.getY())) - ((b.getY() - point.getY()) * (c.getX() - point.getX())) < 0);
	sign[2] = (((c.getX() - point.getX()) * (a.getY() - point.getY())) - ((c.getY() - point.getY()) * (a.getX() - point.getX())) < 0);
	if (sign[0] == sign[1] && sign[1] == sign[2])
		return true;
	return false;
}