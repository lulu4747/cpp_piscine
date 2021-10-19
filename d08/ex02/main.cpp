#include <iostream>
#include <list>
#include "mutantstack.hpp"

int main()
{

	std::cout << "Generating" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "size : " << mstack.size() << std::endl << std::endl;

	mstack.push(17);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "size : " << mstack.size() << std::endl << std::endl;

	mstack.pop();
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "size : " << mstack.size() << std::endl << std::endl;

	mstack.push(3);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "size : " << mstack.size() << std::endl << std::endl;

	mstack.push(5);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "size : " << mstack.size() << std::endl << std::endl;

	mstack.push(737);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "size : " << mstack.size() << std::endl << std::endl;

	mstack.push(0);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "size : " << mstack.size() << std::endl << std::endl;


	std::cout << "Iterators" << std::endl << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Showing iterator incrementation" << std::endl;
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;

	std::cout << std::endl << "looping trough mstack" << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	std::cout << std::endl << "Reverse Iterators" << std::endl << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << "Showing reverse iterator incrementation" << std::endl;
	std::cout << *rit << std::endl;
	++rit;
	std::cout << *rit << std::endl;
	--rit;
	std::cout << *rit << std::endl;

	std::cout << std::endl << "looping trough mstack" << std::endl;
    while(rit != rite){
        std::cout << *rit << std::endl;
        ++rit;
    }

	return 0;
}