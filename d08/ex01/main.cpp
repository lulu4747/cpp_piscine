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
	for (size_t i = 0; i < 10000; i++)
	{
		sp2.addNumber(i);
		std::cout << " | " << i;
	}

	std::cout << std::endl << std::endl << "shortest = " << sp2.shortestSpan() << std::endl;
	std::cout << "longest = " << sp2.longestSpan() << std::endl << std::endl;

	std::cout << "Generating 10000 random values in a vector and adding them in Span" << std::endl << std::endl;

	std::vector<int>	values(10000, 0);
	std::srand(std::time(nullptr));
	for (size_t i = 0; i < 10000; i++)
	{
		values[i] = std::rand();
		std::cout << " | " << values[i];
	}

	try
	{
		sp2.addNumber(values.begin(), values.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << std::endl << "shortest = " << sp2.shortestSpan() << std::endl;
	std::cout << "longest = " << sp2.longestSpan() << std::endl;

	std::cout << std::endl << std::endl << "Copy constructor" << std::endl;
	Span sp3(sp2);

	std::cout << std::endl << "shortest = " << sp2.shortestSpan() << std::endl;
	std::cout << "longest = " << sp2.longestSpan() << std::endl;

	std::cout << std::endl << "Assignation operator" << std::endl;
	sp = sp3;

	std::cout << std::endl << "shortest = " << sp2.shortestSpan() << std::endl;
	std::cout << "longest = " << sp2.longestSpan() << std::endl;


	std::cout << std::endl << std::endl << "Adding 1 value in the vector and attempting addNumber" << std::endl;
	values.push_back(0);

	try
	{
		sp.addNumber(values.begin(), values.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return 0;
}
//copy a revoir : add copy exception ou enlever const _size  gerer la memoire pour copier + add test pour 1000 et add assignation par iterateur;
