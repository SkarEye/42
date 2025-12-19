/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:20:18 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/18 13:01:06 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#define ANSI_RED		"\033[31m"
#define ANSI_GREEN		"\033[32m"
#define ANSI_YELLOW		"\033[33m"
#define ANSI_SCAVTRAP	ANSI_BOLD << "\033[38;5;88m"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	LOG_DEBUG("[ScavTrap] Default constructor called");
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	LOG_DEBUG("[ScavTrap] Parameterized constructor called");
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) :	ClapTrap()
{
	LOG_DEBUG("[ScavTrap] Copy constructor called");
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	LOG_DEBUG("[ScavTrap] Assignment operator called");
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	LOG_DEBUG("[ScavTrap] Destructor called");

}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "ScavTrap "
					<< ANSI_SCAVTRAP
					<<this->_name
					<< ANSI_RESET << ANSI_RED
					<< " ain't gonna attack, it is scavv'ed !"
					<< ANSI_RESET;
	}
	else if (this->_energyPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "ScavTrap "
					<< ANSI_SCAVTRAP
					<< this->_name
					<< ANSI_RESET << ANSI_RED
					<< " ain't attackin nuthin', it's hittin' dem Zzz...s !"
					<< ANSI_RESET;
	}
	else
	{
		this->_energyPoints--;
		std::cout	<< "ScavTrap "
					<< ANSI_SCAVTRAP
					<< this->_name
					<< ANSI_RESET
					<< " ATTTTTTACCCCKS "
					<< ANSI_BOLD << ANSI_RED
					<< target
					<< ANSI_RESET
					<< ", causing "
					<< ANSI_BOLD << ANSI_RED
					<< this->_attackDamage
					<< ANSI_RESET
					<<" point(s) of damage !";
	}
	std::cout << '\n';
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "ScavTrap "
					<< ANSI_SCAVTRAP
					<<this->_name
					<< ANSI_RESET << ANSI_RED
					<< " ain't gonna guard the damn gate, it is scavv'ed !"
					<< ANSI_RESET;
	}
	else if (this->_energyPoints < 1)
	{
		std::cout	<< ANSI_RED
					<< "ScavTrap "
					<< ANSI_SCAVTRAP
					<< this->_name
					<< ANSI_RESET << ANSI_RED
					<< " ain't guardin' nuthin', it's hittin' dem Zzz...s !"
					<< ANSI_RESET;
	}
	else
	{
		this->_energyPoints--;
		std::cout	<< "ScavTrap "
					<< ANSI_SCAVTRAP
					<< this->_name
					<< ANSI_RESET
					<< " IS GUARDING THE GATE !!!";
	}
	std::cout << '\n';
}
