#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <vector>

class Span{

public :

	Span(unsigned int n);
	virtual ~Span(void);

	unsigned int		size(void) const;
	unsigned int		capacity(void) const;
	std::vector<int>	getNumbers(void) const;

	void	addNumber(int n);

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

	int	shortestSpan(void);
	int	longestSpan(void);

private:

	Span(void);
	Span(Span const & src);
	Span &	operator=(Span const & rhs);

	std::vector<int>	_numbers;

};

#endif
