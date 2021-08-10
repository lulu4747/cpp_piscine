#include <iostream>
#include "Array.hpp"

int main( void ){

	Array<int>	iemptyarray; //default
	Array<int>	ifullarray(10); //assignment
	Array<char>	carray(10); //assignment
	Array<char>	ccpyarray(10);

	//Arrays assignment
	for (size_t i = 0; i < ifullarray.size(); i++)
		ifullarray[i] = 5;
	for (size_t i = 0; i < carray.size(); i++)
		carray[i] = '0';

	//Arrays display
	for (size_t i = 0; i < ifullarray.size(); i++)
		std::cout << ifullarray[i];
	std::cout << std::endl;
	for (size_t i = 0; i < carray.size(); i++)
		std::cout << carray[i];
	std::cout << std::endl;

	//assignation operator + display
	ccpyarray = carray;
	for (size_t i = 0; i < ccpyarray.size(); i++)
		std::cout << ccpyarray[i];
	std::cout << std::endl;

	//out of range access
	try
	{
		std::cout << iemptyarray[0];
	}
	catch(const std::exception& e)
	{
		std::cout << "index was out of range" << std::endl;
	}
	try
	{
		std::cout << ifullarray[-1];
	}
	catch(const std::exception& e)
	{
		std::cout << "index was out of range" << std::endl;
	}
	try
	{
		std::cout << ifullarray[11];
	}
	catch(const std::exception& e)
	{
		std::cout << "index was out of range" << std::endl;
	}
	
	return 0;
}