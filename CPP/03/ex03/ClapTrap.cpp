/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:05:46 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/18 09:47:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

#define ANSI_RED		"\033[31m"
#define ANSI_GREEN		"\033[32m"
#define ANSI_YELLOW		"\033[33m"
#define ANSI_CLAPTRAP	ANSI_BOLD << "\033[38;5;208m"


ClapTrap::ClapTrap(void) :	_name("ClapTrap"),
							_hitPoints(10),
							_energyPoints(10),
							_attackDamage(0)
{
	LOG_DEBUG("[ClapTrap] Default constructor called");
}

ClapTrap::ClapTrap(const std::string &name) :	_name(name),
												_hitPoints(10),
												_energyPoints(10),
												_attackDamage(0)
{
	LOG_DEBUG("[ClapTrap] Parameterized constructor called");
}

ClapTrap::ClapTrap(const ClapTrap &other) :	_name(other._name),
											_hitPoints(other._hitPoints),
											_energyPoints(other._energyPoints),
											_attackDamage(other._attackDamage)
{
	LOG_DEBUG("[ClapTrap] Copy constructor called");
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{
	LOG_DEBUG("[ClapTrap] Assignment operator called");
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	LOG_DEBUG("[ClapTrap] Destructor called");

}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "ClapTrap "
					<< ANSI_CLAPTRAP
					<<this->_name
					<< ANSI_RESET << ANSI_RED
					<< " cannot attack, it is kaput !"
					<< ANSI_RESET;
	}
	else if (this->_energyPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "ClapTrap "
					<< ANSI_CLAPTRAP
					<< this->_name
					<< ANSI_RESET << ANSI_RED
					<< " is to tired to attack !"
					<< ANSI_RESET;
	}
	else
	{
		std::cout	<< "ClapTrap "
					<< ANSI_CLAPTRAP
					<< this->_name
					<< ANSI_RESET
					<< " attacks "
					<< ANSI_BOLD << ANSI_RED
					<< target
					<< ANSI_RESET
					<< ", causing "
					<< ANSI_BOLD << ANSI_RED
					<< this->_attackDamage
					<< ANSI_RESET
					<<" point(s) of damage !";
		this->_energyPoints--;
	}
	std::cout << '\n';
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout	<< ANSI_YELLOW
					<< "ClapTrap "
					<< ANSI_CLAPTRAP
					<< this->_name
					<< ANSI_RESET << ANSI_YELLOW
					<< " would have been dealt "
					<< ANSI_BOLD << ANSI_RED
					<< amount
					<< ANSI_RESET << ANSI_YELLOW
					<< " point(s) of damage, were it not already kaput !"
					<< ANSI_RESET;
	}
	else
	{
		std::cout	<< "ClapTrap "
					<< ANSI_CLAPTRAP
					<< this->_name
					<< ANSI_RESET
					<< " is dealt "
					<< ANSI_BOLD << ANSI_RED
					<< amount
					<< ANSI_RESET
					<<" point(s) of damage !";
		if (this->_hitPoints <= amount)
		{
			std::cout << " It explodes in a fireworks of sparkles !";
			this->_hitPoints = 0;
		}
		else
			this->_hitPoints -= amount;
	}
	std::cout << '\n';
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "ClapTrap "
					<< ANSI_CLAPTRAP
					<<this->_name
					<< ANSI_RESET << ANSI_RED
					<< " cannot repair itself, it is kaput !"
					<< ANSI_RESET;
	}
	else if (this->_energyPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "ClapTrap "
					<< ANSI_CLAPTRAP
					<< this->_name
					<< ANSI_RESET << ANSI_RED
					<< " is to tired to repair itself !"
					<< ANSI_RESET;
	}
	else
	{
		std::cout	<< "ClapTrap "
					<< ANSI_CLAPTRAP
					<< this->_name
					<< ANSI_RESET
					<< " repairs itself, healing "
					<< ANSI_BOLD << ANSI_GREEN
					<< amount
					<< ANSI_RESET
					<<" point(s) of hit points !";
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	std::cout << '\n';
}
