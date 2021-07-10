#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	Phonebook {

public :

	Phonebook(void);
	~Phonebook(void);

	void		add(void);
	void		search(void);

	int			get_assigned_number(void);

private :

	void		print(void);

	Contact		_contact[8];
	size_t		_assigned_number;
	size_t		_oldest;

	const char *const _field_name [5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

};

# endif