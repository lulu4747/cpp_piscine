#include <iostream>
#include "Literal.hpp"

int main(int ac, char **av) {

	if (ac == 1)
		return 0;
	for (int i = 1; i < ac; i++)
		std::cout << Literal(av[i]) << std::endl;
	return 0;
}
