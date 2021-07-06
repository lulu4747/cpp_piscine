# include "contact.hpp"

contact::contact(void){

	std::cout << "Contact constructor called" << std::endl;
	this->_field_name = 0; //trouves un moyen d initialiser une constante
	return ;
}

phonebook::~phonebook(void){

	std::cout << "Contact destructor called" << std::endl;
	return ;
}