#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){

	return ;
}

Contact::~Contact(void){

	for (size_t i = 0; i < 5; i++)
		this->_field[i] = "";
	return ;
}


std::string	Contact::get_field(size_t i){

	return (this->_field[i]);
}

void	Contact::set_field(size_t i){

	std::getline(std::cin, this->_field[i]);
	return ;
}
