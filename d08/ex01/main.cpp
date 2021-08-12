#include <iostream>
#include <exception>
#include "span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(7);	
	}
	catch(const std::exception& e)
	{
		std::cout << "addNumber impossible (Span full)" << std::endl;
	}

	Span	sp2 = Span(10);

	sp2.addNumber(8);
	sp2.addNumber(-9);
	sp2.addNumber(5);
	sp2.addNumber(0);
	sp2.addNumber(987);
	sp2.addNumber(41);
	sp2.addNumber(66);
	sp2.addNumber(87);
	sp2.addNumber(7);
	sp2.addNumber(-9);

	try
	{
		sp = sp2;	
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible assignation from sp2" << std::endl;
	}

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}