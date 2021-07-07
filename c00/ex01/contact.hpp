#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	contact {

public :

	contact(void);
	~contact(void);

	std::string	get_field(size_t i);
	void		set_field(size_t i);

private :

	std::string	_field[5];

};

# endif
