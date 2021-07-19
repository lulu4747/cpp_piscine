#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void) {

	size_t	n;

	std::cout << "Animals array size = ";
	std::cin >> n;

	Animal* animals[n];

	for (size_t i = 0; i < n; i++)
	{
		std::cout << i << " : ";
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << std::endl;
	}
	for (size_t i = 0; i < n; i++)	
		delete animals[i];
	/*
	std::cout << std::endl << "Showing deep copy :" <<std::endl;

	Cat*	cat1 = new Cat();
	Cat* 	cat2 = new Cat(*cat1);
	delete cat1;
	delete cat2;*/

	return 0;
}
