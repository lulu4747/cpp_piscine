#include <iostream>
#include "contact.hpp"

contact::contact(void){

	return ;
}

contact::~contact(void){

	for (size_t i = 0; i < 5; i++)
		this->_field[i] = "";
	return ;
}


std::string	contact::get_field(size_t i){

	return (this->_field[i]);
}

void	contact::set_field(size_t i){

	std::getline(std::cin, this->_field[i]);
	return ;
}
