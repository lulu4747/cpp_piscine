#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <stdexcept>
#include "Literal.hpp"

Literal::Literal(void){

	return ;
}

Literal::Literal(Literal const & src){

	*this = src;
	return ;
}

Literal::Literal(std::string const & src){

	for (int i = 0; i < 5; i++)
	{
		if ((this->*_isType[i])(src) == true)
			i = 5;
	}
	return ;
}

Literal::~Literal(void){

	return ;
}

Literal &	Literal::operator=(Literal const & rhs){

	if (this != &rhs)
	{
		this->_c = rhs.getChar();
		this->_i = rhs.getInt();
		this->_f = rhs.getFloat();
		this->_d = rhs.getDouble();
	}
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
			Literal::CastAll(this->_f = std::numeric_limits<float>::infinity());

		else if (!src.compare("-inff"))
			Literal::CastAll(this->_f = -(std::numeric_limits<float>::infinity()));

		else if (!src.compare("nanf"))
			Literal::CastAll(this->_f = std::numeric_limits<float>::quiet_NaN());

		else if (!src.compare("+inf"))
			Literal::CastAll(this->_d = std::numeric_limits<double>::infinity());

		else if (!src.compare("-inf"))
			Literal::CastAll(this->_d = -(std::numeric_limits<double>::infinity()));

		else if (!src.compare("nan"))
			Literal::CastAll(this->_d = std::numeric_limits<double>::quiet_NaN());
	}
	return false;
}

bool	Literal::isChar(std::string const & src){}

bool	Literal::isInt(std::string const & src){}

bool	Literal::isFloat(std::string const & src){}

bool	Literal::isDouble(std::string const & src){}

void	Literal::CastAll(char c){
//pense except
	this->_i = static_cast<int>(c);
}

void	Literal::CastAll(int i){}

void	Literal::CastAll(float f){


}

void	Literal::CastAll(double d){}

std::ostream &	operator<<(std::ostream & o, Literal const & rhs){}
