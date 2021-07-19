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
	
	std::cout << std::endl << "Showing deep copy :" <<std::endl;

	Cat*	cat1 = new Cat();

	cat1->getBrain()->setIdea(0, "I am smart");

	Cat* 	cat2 = new Cat(*cat1);

	std::cout << std::endl << cat1->getType() << " | " << cat2->getType() << std::endl;
	std::cout << std::endl << cat1->getBrain()->getIdea(0) << " | " << cat2->getBrain()->getIdea(0) << std::endl;
	cat1->setType("A particular kind of cat");
	cat2->setType("Another type of cat");
	cat2->getBrain()->setIdea(0, "I am dumb");
	std::cout << std::endl << cat1->getType() << " | " << cat2->getType() << std::endl;
	std::cout << std::endl << cat1->getBrain()->getIdea(0) << " | " << cat2->getBrain()->getIdea(0) << std::endl << std::endl;

	delete cat1;
	delete cat2;

	return 0;
}
