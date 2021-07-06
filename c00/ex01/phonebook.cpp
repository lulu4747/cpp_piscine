#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

phonebook::phonebook(void){

	std::cout << "Phonebook constructor called" << std::endl;
	this->_assigned_number = 0;
	this->_oldest = 0;
	return ;
}

phonebook::~phonebook(void){

	std::cout << "Phonebook destructor called" << std::endl;
	return ;
}

phonebook::add(void){

	size_t		n;
	std::string	buffer;

	if (this->_assigned_number < 8)
	{
		n = this->_assigned_number;
		this->_assigned_number++;
	}
	else
	{
		n = this->oldest;
		if (this->oldest + 1 < 8)
			this->oldest++;
		else
			this->oldest = 0;
	}
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Please enter new contact's " << this->contact::_field_name[i] << " :" << std::endl;
		std::cin >> buffer;
		this->_contact[n]::_field[i] = buffer;
	}
	return ;
}

phonebook::search(void){

	for (size_t i = 0; i < 4; i++)
		std::cout << this->contact::_field_name[i] << "	|	";
	std::cout << this->contact::_field_name[i] << std::endl;

	for (size_t i = 0; i < this->_assigned_number; i++)
	{
		for (size_t j = 0; j < 5; j++)
			std::cout << this->contact[i]::_field[j] << "	|	";
		std::cout << this->contact[i]::_field[j] << std::endl;
	}
	return ;
}