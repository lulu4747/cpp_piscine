#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){

	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src){

	static_cast<void>(src);
	return ;
}

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const & rhs){

	static_cast<void>(rhs);
	return *this;
}

ScalarConverter::ScalarConverter(std::string const & src):_unset(false), _pseudo(false){
 
	this->_isType[0] = &ScalarConverter::_isChar;
	this->_isType[1] = &ScalarConverter::_isFloat;
	this->_isType[2] = &ScalarConverter::_isDouble;
	this->_isType[3] = &ScalarConverter::_isInt;
	this->_isType[4] = &ScalarConverter::_isUnset;

	this->_setPrecision(src);
	this->_isPseudoLiteral(src);

	for (int i = 0; i < 4; i++)
	{
		if ((this->*_isType[i])(src) == true)
			break;
	}
	return ;
}

ScalarConverter::~ScalarConverter(void){

	return ;
}

int		ScalarConverter::getPrecision(void) const{

	return this->_precision;
}

char	ScalarConverter::getChar(void) const{

	return this->_c;
}

int		ScalarConverter::getInt(void) const{

	return this->_i;
}

float	ScalarConverter::getFloat(void) const{

	return this->_f;
}

double	ScalarConverter::getDouble(void) const{

	return this->_d;
}

bool	ScalarConverter::getUnset(void) const{

	return this->_unset;
}

bool	ScalarConverter::getPseudo(void) const{

	return this->_pseudo;
}

void	ScalarConverter::_setPrecision(std::string const & src){

	this->_precision = 0;

	for (size_t	i = src.find('.');
			i != std::string::npos && i + 1 < src.size() && src.at(i + 1) != 'f';
		i++)
	{
		this->_precision++;
	}
	if (this->_precision == 0)
		this->_precision++;
	return ;
}

void	ScalarConverter::_isPseudoLiteral(std::string const & src){

	if (!src.compare("+inff") || !src.compare("-inff") || !src.compare("nanf")
		|| !src.compare("+inff") || !src.compare("-inff") || !src.compare("nan"))
		this->_pseudo = true;
	return ;
}

bool	ScalarConverter::_isChar(std::string const & src){

	if (src.size() != 1 || !isprint(src.at(0)))
		return false;
	try
	{
		this->_c = src.at(0);
		this->CastAll(this->_c);
	}
	catch(const std::exception& e)
	{
		this->_unset = true;
	}
	return true;
}

bool	ScalarConverter::_isFloat(std::string const & src){

	bool	point = false;

	if (src.at(src.size() - 1) != 'f')
		return false;
	if (this->_pseudo == false)
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
		this->_f = atof(src.c_str());
		this->CastAll(this->_f);
	}
	catch(const std::exception& e)
	{
		this->_unset = true;
	}
	return true;
}

bool	ScalarConverter::_isDouble(std::string const & src){

	bool	point = false;

	if (this->_pseudo == false)
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
		this->_d = strtod(src.c_str(), NULL);
		this->CastAll(this->_d);
	}
	catch(const std::exception& e)
	{
		this->_unset = true;
	}
	return true;
}

bool	ScalarConverter::_isInt(std::string const & src){

	for (size_t i = 0; i < src.size(); i++)
	{
		if (!std::isdigit(src.at(i)))
			return false;
	}

	try
	{
		this->_i = atoi(src.c_str());
		this->CastAll(this->_i);
	}
	catch(const std::exception& e)
	{
		this->_unset = true;
	}
	return true;
}

bool	ScalarConverter::_isUnset(std::string const & src){

	static_cast<void>(src);
	return this->_unset = true;
}

void	ScalarConverter::CastAll(char c){

	this->_i = static_cast<int>(c);
	this->_f = static_cast<float>(c);
	this->_d = static_cast<double>(c);
	return ;
}

void	ScalarConverter::CastAll(int i){

	this->_c = static_cast<char>(i);
	this->_f = static_cast<float>(i);
	this->_d = static_cast<double>(i);
	return ;
}

void	ScalarConverter::CastAll(float f){

	this->_c = static_cast<char>(f);
	this->_i = static_cast<int>(f);
	this->_d = static_cast<double>(f);
	return ;
}

void	ScalarConverter::CastAll(double d){

	this->_c = static_cast<char>(d);
	this->_i = static_cast<int>(d);
	this->_f = static_cast<float>(d);
	return ;
}

std::ostream &	operator<<(std::ostream & o, ScalarConverter const & rhs){

	o << "char: ";
	if (rhs.getUnset() == true || rhs.getPseudo() == true)
		o << "impossible" << std::endl;
	else if (!isprint(rhs.getChar()))
		o << "Non displayable" << std::endl;
	else
		o << rhs.getChar() << std::endl;

	o << "int: ";
	if (rhs.getUnset() == true || rhs.getPseudo() == true)
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
