/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:20:18 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/18 13:54:24 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#define ANSI_RED		"\033[31m"
#define ANSI_GREEN		"\033[32m"
#define ANSI_YELLOW		"\033[33m"
#define ANSI_FRAGTRAP	ANSI_BOLD << "\033[38;5;218m"

FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	LOG_DEBUG("[FragTrap] Default constructor called");
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	LOG_DEBUG("[FragTrap] Parameterized constructor called");
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) :	ClapTrap(other)
{
	LOG_DEBUG("[FragTrap] Copy constructor called");
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	LOG_DEBUG("[FragTrap] Assignment operator called");
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	LOG_DEBUG("[FragTrap] Destructor called");

}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "FragTrap "
					<< ANSI_FRAGTRAP
					<<this->_name
					<< ANSI_RESET << ANSI_RED
					<< " would let it be known it is incapacitated and cannot high-five."
					<< ANSI_RESET;
	}
	else if (this->_energyPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "FragTrap "
					<< ANSI_FRAGTRAP
					<< this->_name
					<< ANSI_RESET << ANSI_RED
					<< " would inform you that it doesn't have the energy to high-five."
					<< ANSI_RESET;
	}
	else
	{
		this->_energyPoints--;
		std::cout	<< "FragTrap "
					<< ANSI_FRAGTRAP
					<< this->_name
					<< ANSI_RESET
					<< " holds its hand up, raring itself for a high-five !";
	}
	std::cout << '\n';
}
