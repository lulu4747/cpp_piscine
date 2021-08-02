#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <stdexcept>
#include "Literal.hpp"

Literal::Literal(std::string const & src):_unset(false){

	for (int i = 0; i < 6; i++)
	{
		if ((this->*_isType[i])(src) == true)
			break;
	}
	return ;
}

Literal::~Literal(void){

	return ;
}

char	Literal::getChar(void) const{

	return this->_c;
}

int		Literal::getInt(void) const{

	return this->_i;
}

float	Literal::getFloat(void) const{

	return this->_f;
}

double	Literal::getDouble(void) const{

	return this->_d;
}

bool	Literal::isPseudo(std::string const & src){

	if (src.size() <= 5)
	{
		if (!src.compare("+inff"))
			Literal::CastAll(this->_f = Literal::inff);

		else if (!src.compare("-inff"))
			Literal::CastAll(this->_f = -Literal::inff);

		else if (!src.compare("nanf"))
			Literal::CastAll(this->_f = Literal::nanf);

		else if (!src.compare("+inf"))
			Literal::CastAll(this->_d = Literal::inf);

		else if (!src.compare("-inf"))
			Literal::CastAll(this->_d = -Literal::inf);

		else if (!src.compare("nan"))
			Literal::CastAll(this->_d = Literal::nan);
	}
	return false;
}

bool	Literal::isChar(std::string const & src){

	if (src.size() == 1 && std::isprint(src.at(0)))
	{
		Literal::CastAll(this->_c = src.at(0));
		return true;
	}
	return false
}

bool	Literal::isInt(std::string const & src){

	for (int i = 0; i < src.size(); i++)
	{
		if (!std::isdigit(src.at(i)))
			return false;
	}
}

bool	Literal::isFloat(std::string const & src){}

bool	Literal::isDouble(std::string const & src){}

bool	Literal::isUnset(std::string const & src){

	return this->_unset = true;
}

void	Literal::CastAll(char c){

	this->_i = static_cast<int>(c);
	this->_f = static_cast<float>(i);
	this->_d = static_cast<double>(i);
	return ;
}

void	Literal::CastAll(int i){

	this->_c = static_cast<char>(i);
	this->_f = static_cast<float>(i);
	this->_d = static_cast<double>(i);
	return ;
}

void	Literal::CastAll(float f){

	this->_c = static_cast<char>(f);
	this->_i = static_cast<int>(f);
	this->_d = static_cast<double>(f);
	return ;
}

void	Literal::CastAll(double d){

	this->_c = static_cast<char>(d);
	this->_i = static_cast<int>(d);
	this->_f = static_cast<float>(d);
	return ;
}

std::ostream &	operator<<(std::ostream & o, Literal const & rhs){}
