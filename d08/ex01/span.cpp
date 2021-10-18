#include <exception>
#include <algorithm>
#include <vector>
#include "span.hpp"

/*
----------Member Functions----------
*/

Span::Span(unsigned int n){

	this->_numbers.reserve(n);
	return ;
}

Span::~Span(void){

	return ;
}

unsigned int		Span::size(void) const{

	return this->_numbers.size();
}

unsigned int		Span::capacity(void) const{

	return this->_numbers.capacity();
}

std::vector<int>	Span::getNumbers(void) const{

	return this->_numbers;
}

void	Span::addNumber(int n){

	if (this->size() >= this->capacity())
		throw FullClassException();
	this->_numbers.push_back(n);
	return ;
}

int	Span::shortestSpan(void){

	if (this->size() <= 1)
		throw ImpossibleSpanException();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	return *(++this->_numbers.begin()) - *this->_numbers.begin();
}

int	Span::longestSpan(void){

	if (this->size() <= 1)
		throw ImpossibleSpanException();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	return *this->_numbers.rbegin() - *this->_numbers.begin();
}
