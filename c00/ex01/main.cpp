#include <iostream>
#include "phonebook.hpp"

int	main(void){

	phonebook	phone;
	std::string input;

	std::cin >> input;
	while (input.compare("EXIT"))
	{
		if (!(input.compare("ADD")))
			phone.add();
		else if (!(input.compare("SEARCH"))){
			if (!(phone.get_assigned_number()))
				std::cout << "No contact registered yet. Add contacts using \"ADD\" command" << std::endl;
			else
				phone.search();
		}
		std::cin >> input;
	}
	return (0);
}