#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ){

	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){

	return (_totalAmount);
}

int	Account::getNbDeposits( void ){

	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){

	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){


	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			<<  ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
	return ;
}

Account::Account( int initial_deposit ):_amount(initial_deposit){

	_totalAmount += initial_deposit;

	this->_accountIndex = this->getNbAccounts();
	this->_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ){

	_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ){

	int	p_amount = this->_amount;

	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
			<< ";deposit:" << deposit << ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;

	return ;
}

bool	Account::makeWithdrawal( int withdrawal ){

	int	p_amount = this->_amount;
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:";
	this->_amount -= withdrawal;
	if (this->_amount >= 0)
	{
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals;
	}
	else
	{
		this->_amount = p_amount;
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const{

	return (this->_amount);
}

void	Account::displayStatus( void ) const{

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return ;
}

void	Account::_displayTimestamp( void ){

	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	std::cout << "["
		<< timePtr->tm_year + 1900
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_mon + 1
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_mday
		<< "_"
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_hour
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_min
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_sec
		<< "] ";
}
