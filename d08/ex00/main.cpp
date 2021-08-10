#include <iostream>
#include <list>
#include "easyfind.hpp"

int main( void ){

	std::list<int> lst;

	//assigning
	for (int i = 0; i < 11; i++)
		lst.push_back(i);

	//easyfind in range
	try
	{
		std::cout << easyfind(lst, 5) << std::endl;
	}
	catch (std::out_of_range & oor)
	{
		std::cout << oor.what() << std::endl;
	}

	//easyfind out of range
	try
	{
		std::cout << easyfind(lst, 12) << std::endl;
	}
	catch (std::out_of_range & oor)
	{
		std::cout << oor.what() << std::endl;
	}

	return 0;
}