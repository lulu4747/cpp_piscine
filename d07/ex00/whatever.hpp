#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void	swap(T & x, T & y){

	T	tmp = x;

	x = y;
	y = tmp;
	return ;
}

template< typename T >
T	min(T const & x, T const & y){

	if (x < y)
		return x;
	return y;
}

template< typename T >
T	max(T const & x, T const & y){

	if (x > y)
		return x;
	return y;
}

#endif