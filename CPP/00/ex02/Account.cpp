/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:18:21 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 13:30:54 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t	t;
	char	buf[24];

	time(&t);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", localtime(&t));
	std::cout << buf;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int		p_amount = this->_amount;
	bool	accepted = (withdrawal <= this->_amount);

	if (accepted)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << p_amount;
	if (!accepted)
		std::cout	<< ";withdrawal:refused" << std::endl;
	else
	{
		std::cout	<< ";withdrawal:" << withdrawal
					<< ";amount:" << this->_amount
					<< ";nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
	}
	return (accepted);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}
