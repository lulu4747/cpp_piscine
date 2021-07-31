#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	Bureaucrat Joel("Joel", 5);
	Form*	test;

	try{
		test = new Form("test", 151, 151);}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';}
	try{
		test = new Form("test", 0, 0);}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';}
	try{
		test = new Form("test", 4, 8);}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';}

	std::cout << *test << std::endl;

	Joel.signForm(*test);
	try{
	test->beSigned(Joel);}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';}

	std::cout << *test << std::endl;

	Joel.upgrade();

	Joel.signForm(*test);
	try{
	test->beSigned(Joel);}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';}

	std::cout << *test << std::endl;

	delete test;
	return 0;
}
