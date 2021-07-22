#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {

	try{
		Bureaucrat	Gwendo("Gwendolyne", 1);
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try{
	Bureaucrat	Lionel("Lionel", 150);
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try{	
		Bureaucrat	George("George", 0);
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try{	
		Bureaucrat	Simon("Simon", 151);
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
/*
	Gwendo.upgrade();
	Gwendo.downgrade();
	Lionel.upgrade();
	Lionel.downgrade();*/

	return 0;
}

//use pointer instead of this crao shit