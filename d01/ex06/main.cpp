#include <iostream>
#include <string>
#include "Karen.hpp"

int	main(int ac, char **av){

	Karen	Karen;

	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}

	std::string	level = av[1];
	size_t				i = 0;

	while (i < 4 && level.compare(Karen.getFunctionTabLevel(i)))
		i++;
	switch (i) {
	
		case 0: Karen.complain("DEBUG");
		case 1: Karen.complain("INFO");
		case 2: Karen.complain("WARNING");
		case 3: Karen.complain("ERROR");
				break;
		default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}