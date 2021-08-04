#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cctype>
#include <limits>
#include <sstream>
#include <stdexcept>
#include "Literal.hpp"

Literal::Literal(void){

	return ;
}

Literal::Literal(Literal const & src){

	static_cast<void>(src);
	return ;
}

Literal &	Literal::operator=(Literal const & rhs){

	static_cast<void>(rhs);
	return *this;
}

Literal::Literal(std::string const & src):_unset(false){
 
	this->_isType[0] = &Literal::isFloat;
	this->_isType[1] = &Literal::isDouble;
	this->_isType[2] = &Literal::isInt;
	this->_isType[3] = &Literal::isUnset;

	this->_setPrecision(src);

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

int		Literal::getPrecision(void) const{

	return this->_precision;
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

bool	Literal::getUnset(void) const{

	return this->_unset;
}

void	Literal::_setPrecision(std::string const & src){

	this->_precision = 0;

	for (size_t	i = src.find('.') + 1;
			i != std::string::npos && src.at(0) != 'f' && i < src.size();
		i++)
	{
		this->_precision++;
	}
	if (this->_precision == 0)
		this->_precision++;
	return ;
}

bool	Literal::isFloat(std::string const & src){

	bool	point = false;

	if (src.at(src.size() - 1) != 'f')
		return false;
	if (src.compare("+inff") && src.compare("-inff") && src.compare("nanf"))
	{
		for (size_t i = 0; i < src.size() - 1; i++)
		{
			if (!std::isdigit(src.at(i)))
			{
				if (point == false && src.at(i) == '.')
					point = true;
				else
					return false;
			}
		}
	}
	try
	{
		std::stringstream	ss;

		ss << src;
		ss >> this->_f;
		this->CastAll(this->_f);
	}
	catch(const std::exception& e)
	{
		this->_unset = true;
	}
	return true;
}

bool	Literal::isDouble(std::string const & src){

	bool	point = false;

	if (src.compare("+inff") && src.compare("-inff") && src.compare("nanf"))
	{
		for (size_t i = 0; i < src.size(); i++)
		{
			if (!std::isdigit(src.at(i)))
			{
				if (point == false && src.at(i) == '.')
					point = true;
				else
					return false;
			}
		}
	}
	try
	{
		std::stringstream	ss;

		ss << src;
		ss >> this->_d;
		this->CastAll(this->_d);
	}
	catch(const std::exception& e)
	{
		this->_unset = true;
	}
	return true;
}

bool	Literal::isInt(std::string const & src){

	for (size_t i = 0; i < src.size(); i++)
	{
		if (!std::isdigit(src.at(i)))
			return false;
	}

	try
	{
		std::stringstream	ss;

		ss << src;
		ss >> this->_i;
		this->CastAll(this->_i);
	}
	catch(const std::exception& e)
	{
		this->_unset = true;
	}
	return true;
}

bool	Literal::isUnset(std::string const & src){

	static_cast<void>(src);
	return this->_unset = true;
}

void	Literal::CastAll(char c){

	this->_i = static_cast<int>(c);
	this->_f = static_cast<float>(c);
	this->_d = static_cast<double>(c);
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

std::ostream &	operator<<(std::ostream & o, Literal const & rhs){

	o << "char: ";
	if (rhs.getUnset() == true)
		o << "impossible" << std::endl;
	else if (!std::isprint(rhs.getChar()))
		o << "Non displayable" << std::endl;
	else
		o << rhs.getChar() << std::endl;

	o << "int: ";
	if (rhs.getUnset() == true)
		o << "impossible" << std::endl;
	else
		o << rhs.getInt() << std::endl;

	o << "float: ";
	if (rhs.getUnset() == true)
		o << "impossible" << std::endl;
	else
		o << std::setprecision(rhs.getPrecision()) << std::fixed << rhs.getFloat() << "f" << std::endl;

	o << "double: ";
	if (rhs.getUnset() == true)
		o << "impossible";
	else
		o << std::setprecision(rhs.getPrecision()) << std::fixed << rhs.getDouble();

	return o;
}
