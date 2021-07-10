#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"

Phonebook::Phonebook(void){

	this->_assigned_number = 0;
	this->_oldest = 0;
	return ;
}

Phonebook::~Phonebook(void){

	return ;
}

int	Phonebook::get_assigned_number(void){

	return (this->_assigned_number);
}

void	Phonebook::add(void){

	size_t		n;

	if (this->_assigned_number < 8)
	{
		n = this->_assigned_number;
		this->_assigned_number++;
	}
	else
	{
		n = this->_oldest;
		if (this->_oldest + 1 < 8)
			this->_oldest++;
		else
			this->_oldest = 0;
	}
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Please enter new contact's " << this->_field_name[i] << " :" << std::endl;
		this->_contact[n].set_field(i);
	}
	std::cout << std::endl << "New contact successfully added !" << std::endl << std::endl;
	return ;
}

void	Phonebook::print(void){

	std::string	str;

	std::cout << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		str = this->_field_name[i];
		if (str.size() <= 10)
		{
			std::cout.width(10);
			std::cout << std::left << str;
		}
		else
		{
			for (size_t j = 0; j < 9; j++)
				std::cout << str.at(j);
			std::cout << ".";
		}
		if (i < 3)
			std::cout << "|";
	}
	std::cout << std::endl;

	contact	contact;

	for (size_t i = 0; i < this->_assigned_number; i++)
	{
		contact = this->_contact[i];
		for (size_t j = 0; j < 4; j++)
		{
			str = contact.get_field(j);
			if (str.size() <= 10)
			{
				std::cout.width(10);
				std::cout << std::left << str;
			}
			else
			{
				for (size_t k = 0; k < 9; k++)
					std::cout << str.at(k);
				std::cout << ".";
			}
			if (j < 3)
				std::cout << "|";
		}
		std::cout << std::endl;
	}
	return ;
}

void	Phonebook::search(void){

	this->print();

	std::string	str;
	
	std::cout << std::endl << "Type a valid index number for details : ";
	std::getline(std::cin, str);
	std::cout << std::endl;

	while (str.size() > 1 || str.at(0) < '1' || str.at(0) > (this->_assigned_number + '0'))
	{
		std::cerr << "Error:Invalid index" << std::endl;
		std::cout << std::endl << "Please type a valid index : ";
		std::getline(std::cin, str);
		std::cout << std::endl;
	}

	size_t 	i 		= 	str.at(0) - '0';
	contact	contact =	this->_contact[i - 1];

	for (size_t j = 0; j < 5; j++)
	{
		str = contact.get_field(j);
		std::cout << str << std::endl;
	}
	std::cout << std::endl;
	return ;
}
