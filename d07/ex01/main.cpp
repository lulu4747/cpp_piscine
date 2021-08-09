#include <iostream>
#include "iter.hpp"

template < typename T>
void	print(T const & c)
{
	std::cout << c;
	return ;
}

int main( void )
{
	int	const array[5] = {0, 1, 2, 3, 4};

	::iter(array, 5, &print<int>);
	std::cout << std::endl;

	::iter("teststring", 10, &print<char>);
	std::cout << std::endl;

	return 0;
}