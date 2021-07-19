#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain{

public:

	Brain(void);
	Brain(Brain const & src);
	virtual ~Brain(void);

	virtual Brain &	operator=(Brain const & rhs);

	virtual std::string	getIdea(size_t index) const;
	virtual void		setIdea(size_t index, std::string str);

private:

	std::string	_ideas[100];

};

#endif