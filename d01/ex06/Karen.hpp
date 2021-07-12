#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen{

public:

	Karen(void);
	~Karen(void);

	void			complain(std::string level);
	std::string		getFunctionTabLevel(size_t i) const;

private:

	void			debug(void);
	void			info(void);
	void			warning(void);
	void			error(void);

	typedef struct	s_func{
		std::string	level;
		void		(Karen::*func)(void);
	}	t_func;

	t_func			_FunctionTab[4];

};

#endif