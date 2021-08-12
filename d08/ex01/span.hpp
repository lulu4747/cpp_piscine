#ifndef SPAN_HPP
#define SPAN_HPP

# include <algorithm>
# include <vector>

class Span{

public :

	Span(unsigned int n);
	Span(Span const & src);
	virtual ~Span(void);

	Span &	operator=(Span const & rhs);

	unsigned int		getSize(void) const;
	unsigned int		getAllocs(void) const;
	std::vector<int> *	getNumbers(void) const;

	void	addNumber(int i);

	int		min(void) const;
	int		max(void) const;

private:

	Span(void);

	unsigned int const	_size;
	unsigned int		_allocs;
	std::vector<int> *	_numbers;

};

#endif