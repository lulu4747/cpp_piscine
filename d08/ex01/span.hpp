#ifndef SPAN_HPP
#define SPAN_HPP

# include <algorithm>
# include <vector>

/*
--------Span class definition--------
*/

class Span{

public :

	Span(unsigned int n);
	Span(Span const & src);
	virtual ~Span(void);

	Span &	operator=(Span const & rhs);

	unsigned int		getSize(void) const;
	unsigned int		getAllocs(void) const;
	std::vector<int>	getNumbers(void) const;

	void	addNumber(int n);

	int		max(void);
	int		min(void);
	int		sup(int	n);

private:

	Span(void);

	unsigned int const	_size;
	unsigned int		_allocs;
	std::vector<int>	_numbers;

};

/*
--------Subjects prototypes--------
*/

int	shortestSpan(Span const & span);
int	longestSpan(Span const & span);

#endif