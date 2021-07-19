#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void) {

	//Animal* animal = new Animal();
	Animal* cat = new Cat();

	std::cout << "To test we must break" << std::endl;

	delete cat;

	return 0;
}
