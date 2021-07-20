#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		c(3.44f);

	std::cout << "At start : a = " << a << "| b = " << b <<" | c = " << c << std::endl;
	std::cout << std::endl << "During ++a : " << ++a << " | After : " << a << std::endl;
	std::cout << std::endl << "During a++ : " << a++ << " | After : " << a << std::endl;
	std::cout << std::endl << "During --a : " << --a << " | After : " << a << std::endl;
	std::cout << std::endl << "During a-- : " << a-- << " | After : " << a << std::endl;
	std::cout << std::endl << "During ++c : " << ++c << " | After : " << c << std::endl;
	std::cout << std::endl << "During c++ : " << c++ << " | After : " << c << std::endl;
	std::cout << std::endl << "During --c : " << --c << " | After : " << c << std::endl;
	std::cout << std::endl << "During c-- : " << c-- << " | After : " << c << std::endl;
	std::cout << std::endl << "a(" << a << ") + c(" << c << ") : " << a + c << std::endl;
	std::cout << std::endl << "a(" << a << ") - c(" << c << ") : " << a - c << std::endl;
	std::cout << std::endl << "a(" << a << ") * c(" << c << ") : " << a * c << std::endl;
	std::cout << std::endl << "a(" << a << ") / c(" << c << ") : " << a / c << std::endl;

	Fixed		same(a);
	Fixed		diffmin(--a); ++a;
	Fixed		diffplus(++a); --a;

	std::cout << std::boolalpha << "Comparison return for : a(" << a << ") == same(" << same << ") : " << (a == same) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") == diffmin(" << diffmin << ") : " << (a == diffmin) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") == diffplus(" << diffplus << ") : " << (a == diffplus) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") != same(" << same << ") : " << (a != same) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") != diffmin(" << diffmin << ") : " << (a != diffmin) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") != diffplus(" << diffplus << ") : " << (a != diffplus) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") >= same(" << same << ") : " << (a >= same) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") >= diffmin(" << diffmin << ") : " << (a >= diffmin) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") >= diffplus(" << diffplus << ") : " << (a >= diffplus) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") <= same(" << same << ") : " << (a <= same) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") <= diffmin(" << diffmin << ") : " << (a <= diffmin) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") <= diffplus(" << diffplus << ") : " << (a <= diffplus) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") > same(" << same << ") : " << (a > same) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") > diffmin(" << diffmin << ") : " << (a > diffmin) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") > diffplus(" << diffplus << ") : " << (a > diffplus) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") < same(" << same << ") : " << (a < same) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") < diffmin(" << diffmin << ") : " << (a < diffmin) << std::endl
				<< std::endl << "Comparison return for : a(" << a << ") < diffplus(" << diffplus << ") : " << (a < diffplus) << std::endl;


	std::cout << std::endl << "max(a(" << a << "), b(" << b << ")) = " << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl << "min(a(" << a << "), b(" << b << ")) = " << Fixed::min( a, b ) << std::endl;
	std::cout << std::endl << "max(a(" << a << "), same(" << same << ")) = " << Fixed::max( a, same ) << std::endl;
	std::cout << std::endl << "min(a(" << a << "), same(" << same << ")) = " << Fixed::min( a, same ) << std::endl;

	return 0;
}
