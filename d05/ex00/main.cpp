#include <iostream>
# include <stdexcept>
#include "Bureaucrat.hpp"

int main(void) {

	Bureaucrat*	Gwendo;
	Bureaucrat*	Lionel;
	Bureaucrat*	George;
	Bureaucrat*	Simon;

	try{
		Gwendo = new Bureaucrat("Gwendolyne", 1);}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;}
	try{
		Lionel = new Bureaucrat("Lionel", 150);}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;}
	try{	
		George = new Bureaucrat("George", 0);}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;}
	try{	
		Simon = new Bureaucrat("Simon", 151);}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;}

	std::cout << "Gwendo grade : " << Gwendo->getGrade() << std::endl
			<< "Lionel grade : " << Lionel->getGrade() << std::endl;

	try{
		Gwendo->upgrade();}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;}

	std::cout << "Gwendo grade : " << Gwendo->getGrade() << std::endl;

	try{
		Gwendo->downgrade();}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;}

	std::cout << "Gwendo grade : " << Gwendo->getGrade() << std::endl;

	try{
		Lionel->downgrade();}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;}

	std::cout << "Lionel grade : " << Lionel->getGrade() << std::endl;

	try{
		Lionel->upgrade();}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;}

	std::cout << "Lionel grade : " << Lionel->getGrade() << std::endl;

	delete Gwendo;
	delete Lionel;

	return 0;
}
