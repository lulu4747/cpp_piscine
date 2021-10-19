#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <iterator>
# include <algorithm>
# include <vector>

class Span{

public :

	Span(unsigned int n);
	virtual ~Span(void);

	Span(Span const & src);
	Span &	operator=(Span const & rhs);

	unsigned int		size(void) const;
	unsigned int		capacity(void) const;
	unsigned int		getMax(void) const;
	std::vector<int>	getNumbers(void) const;

	class	FullClassException : public std::exception{
	public:
		virtual const char *	what() const throw(){
			return ("addNumber error : Class is full");
		}
	};
	class	ImpossibleSpanException : public std::exception{
	public:
		virtual const char *	what() const throw(){
			return ("Impossible Span : 1 or less values stored in class");
		}
	};

	void	addNumber(int n);

	template < class Iterator>
	void	addNumber(Iterator begin, Iterator end)
	{
		if (end - begin > this->_max)
			throw FullClassException();
		std::copy(begin, end, std::back_inserter(this->_numbers));
		return ;
	};


	int	shortestSpan(void);
	int	longestSpan(void);

private:

	Span(void);

	std::vector<int>	_numbers;
	unsigned int		_max;

};

#endif
