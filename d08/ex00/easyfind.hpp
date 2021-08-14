#ifdef EASYFIND_HPP
# include EASYFIND_HPP

# include <exception>

template < typename T >
int easyfind(T container, int n){

	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), n);

	if (it == container.end())
		throw std::out_of_range("out of range");

	return *it;
}

#endif