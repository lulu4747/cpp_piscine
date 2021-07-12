#include <iostream>
#include <string>
#include "Karen.hpp"

Karen::Karen(void){

	this->_FunctionTab[0].level = "DEBUG";
	this->_FunctionTab[0].func = &Karen::debug;
	this->_FunctionTab[1].level = "INFO";
	this->_FunctionTab[1].func = &Karen::info;
	this->_FunctionTab[2].level = "WARNING";
	this->_FunctionTab[2].func = &Karen::warning;
	this->_FunctionTab[3].level = "ERROR";
	this->_FunctionTab[3].func = &Karen::error;

	return ;
}

Karen::~Karen(void){

	return ;
}

void	Karen::complain(std::string level){

	for (size_t i = 0; i < 4; i++)
	{
		if (!(level.compare(this->_FunctionTab[i].level)))
			(this->*_FunctionTab[i].func)();
	}
	return ;
}

void	Karen::debug(void){

	std::cout << "[ DEBUG ]" << std::endl << "I love to get extra bacon for my 7XL-double-cheese-"
				<< "triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
	return ;
}

void	Karen::info(void){

	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon cost more money. "
				<< "You don’t put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
	return ;
}

void	Karen::warning(void){

	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming here for years and you just started working here last month." << std::endl << std::endl;
	return ;
}

void	Karen::error(void){

	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable, I want to speak to the manager "
				<< "now." << std::endl << std::endl;
	return ;
}
