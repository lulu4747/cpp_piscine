#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av) {

	if (ac == 1)
	{
		std::cout << "Usage :" << std::endl << "./convert args..." << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
		std::cout << ScalarConverter(av[i]) << std::endl;
	return 0;
}
