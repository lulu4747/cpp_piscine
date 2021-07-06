#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class	phonebook {

public :

	add(void);
	search(void);

	phonebook(void);
	~phonebook(void);

private :

	contact	_contact[8];
	size_t	_assigned_number;
	size_t	_oldest;
};

# endif