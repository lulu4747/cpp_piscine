#include <exception>
#include <algorithm>
#include <vector>
#include "span.hpp"

/*
----------Member Functions----------
*/

Span::Span(unsigned int n):_size(n),_allocs(0){

	this->_numbers.reserve(n);
	return ;
}

Span::Span(Span const & src):Span(src.getSize()){

	*this = src;
	return ;
}

Span::~Span(void){

	return ;
}

Span &	Span::operator=(Span const & rhs){

	if (this != &rhs)
	{
		if (rhs.getSize() != this->_size)
			throw std::exception();
		this->_allocs = rhs.getAllocs();
		std::copy(rhs.getNumbers().begin(), rhs.getNumbers().end(), this->_numbers.begin());
	}
	return *this;
}

unsigned int		Span::getSize(void) const{

	return this->_size;
}

unsigned int		Span::getAllocs(void) const{

	return this->_allocs;
}

std::vector<int>	Span::getNumbers(void) const{

	return this->_numbers;
}

void	Span::addNumber(int n){

	if (this->_allocs == this->_size)
			throw std::exception();
	this->_numbers.push_back(n);
	std::sort(this->_numbers.begin(), this->_numbers.end());
	return ;
}

int		Span::max(void){

	return *std::max_element(this->_numbers.begin(), this->_numbers.end());
}

int		Span::min(void){

	return *std::min_element(this->_numbers.begin(), this->_numbers.end());
}

int		Span::sup(int n){

	if (this->_size > 1)
		return *(std::find(this->_numbers.begin(), this->_numbers.end(), n)++);
	return n;
}

/*
----------Non Member Functions----------
*/

int	shortestSpan(Span & span){

	return span.sup(span.min()) - span.min();
}

int	longestSpan(Span & span){

	return span.max() - span.min();
}

