/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:37:18 by fzayani           #+#    #+#             */
/*   Updated: 2025/02/05 19:19:04 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
}

Account::Account(void)
{
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";

	if(withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout	 << "withdrawal:" << withdrawal << ";"
				 << "amount:" << _amount << ";"
				 << "nb_withdrawals:" << _nbWithdrawals
				 << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(NULL);
	struct tm *timeinfo = localtime(&now);
	char buffer[19];

	strftime(buffer, 19, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
}