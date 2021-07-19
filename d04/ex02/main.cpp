#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void) {

	//AAnimal* animal = new AAnimal();
	AAnimal* cat = new Cat();

	std::cout << "To test it we must break it" << std::endl;

	delete cat;

	return 0;
}
