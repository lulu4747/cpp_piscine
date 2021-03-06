#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template< class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{

public:

	MutantStack(void): std::stack<T, Container>(){}

	MutantStack(std::stack<T, Container> const & src): std::stack<T, Container>(src){}
	MutantStack(MutantStack const & src): std::stack<T, Container>(src){}

	virtual ~MutantStack(void){}

	MutantStack &	operator=(MutantStack const & rhs){return *this = std::stack<T, Container>::operator=(rhs);}

	typedef	typename Container::iterator				iterator;
	typedef	typename Container::const_iterator			const_iterator;
	typedef	typename Container::reverse_iterator		reverse_iterator;
	typedef	typename Container::const_reverse_iterator	const_reverse_iterator;

	iterator				begin(void){return std::stack<T, Container>::c.begin();}
	const_iterator			begin(void) const{return std::stack<T, Container>::c.begin();}

	iterator				end(void){return std::stack<T, Container>::c.end();}
	const_iterator			end(void) const{return std::stack<T, Container>::c.end();}

	reverse_iterator		rbegin(void){return std::stack<T, Container>::c.rbegin();}
	const_reverse_iterator	rbegin(void) const{return std::stack<T, Container>::c.rbegin();}

	reverse_iterator		rend(void){return std::stack<T, Container>::c.rend();}
	const_reverse_iterator	rend(void) const{return std::stack<T, Container>::c.rend();}

};

#endif