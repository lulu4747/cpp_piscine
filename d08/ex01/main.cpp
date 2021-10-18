#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "span.hpp"

int main()
{
	Span sp(5);

	std::cout << "shortest and longest span with empty class" << std::endl << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}		

	sp.addNumber(5);

	std::cout << std::endl << "shortest and longest span with a single value in class" << std::endl << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << std::endl << "shortest and longest span with values = 5, 3, 17, 9, 11" << std::endl << std::endl;

	std::cout << "shortest = " << sp.shortestSpan() << std::endl;
	std::cout << "longest = " << sp.longestSpan() << std::endl;

	std::cout << std::endl << "adding value in already full class" << std::endl << std::endl;

	try
	{
		sp.addNumber(7);	
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	Span	sp2(10000);
	std::srand(std::time(nullptr));
	for (size_t i = 0; i < 10000; i++)
	{
		sp2.addNumber(i);
		std::cout << " | " << i;
	}
	/*sp2.addNumber(8);
	sp2.addNumber(-9);
	sp2.addNumber(5);
	sp2.addNumber(0);
	sp2.addNumber(987);
	sp2.addNumber(41);
	sp2.addNumber(66);
	sp2.addNumber(87);
	sp2.addNumber(7);
	sp2.addNumber(-9);*/

	std::cout << std::endl << std::endl << "shortest = " << sp2.shortestSpan() << std::endl;
	std::cout << "longest = " << sp2.longestSpan() << std::endl;
	
	for (std::vector<int>::iterator it = sp2.getNumbers().begin(); it < sp2.getNumbers().end(); it++)
	{
		*it = std::rand();
		std::cout << " | " << *it;
	}

	std::cout << std::endl << std::endl << "shortest = " << sp2.shortestSpan() << std::endl;
	std::cout << "longest = " << sp2.longestSpan() << std::endl;


//	std::cout << std::endl << "Huge :" << std::endl;

//	Span	huge(100000);

/*	huge.getNumbers().insert(huge.getNumbers().end(), std::rand());
	for (std::vector<int>::iterator	it = huge.getNumbers().begin();  it != huge.getNumbers().end(); it++)
	{
		*it = std::rand();
		std::cout << *it;
	}
	std::cout << std::endl;
	std::cout << huge.shortestSpan() << std::endl;
	std::cout << huge.longestSpan() << std::endl;*/

	return 0;
}
//copy a revoir : add copy exception ou enlever const _size  gerer la memoire pour copier + add test pour 1000 et add assignation par iterateur;
