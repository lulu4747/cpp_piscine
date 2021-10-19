#include <exception>
#include <algorithm>
#include <vector>
#include "span.hpp"

/*
----------Member Functions----------
*/

Span::Span(unsigned int n):_max(n){

	this->_numbers.reserve(_max);
	return ;
}

Span::~Span(void){

	return ;
}

Span::Span(Span const & src){

	*this = src;
	return ;
}

Span &	Span::operator=(Span const & rhs){

	if (this == &rhs)
		return *this;
	if (this->size() != 0)
		this->_numbers.clear();
	this->_max = rhs.getMax();
	this->_numbers.reserve(this->_max);
	std::copy(rhs.getNumbers().begin(), rhs.getNumbers().end(), std::back_inserter(this->_numbers));
	return *this;
}

unsigned int		Span::size(void) const{

	return this->_numbers.size();
}

unsigned int		Span::capacity(void) const{

	return this->_numbers.capacity();
}

unsigned int		Span::getMax(void) const{

	return this->_max;
}

std::vector<int>	Span::getNumbers(void) const{

	return this->_numbers;
}

void	Span::addNumber(int n){

	if (this->size() >= this->_max)
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
